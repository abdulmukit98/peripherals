#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// WiFi credentials
const char* ssid = "Smart";
const char* password = "menthokol";

// MQTT broker details
const char* mqtt_server = "192.168.0.7"; // OpenHAB server IP
// const char* mqtt_server = "test.mosquitto.org"; // OpenHAB server IP 
const int mqtt_port = 1883;
const char* mqtt_topic = "device/led";
const int ledPin =  LED_BUILTIN;  // GPIO2 on most NodeMCU boards

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
    delay(10);
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void reconnect() {
    // Loop until we're reconnected
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        
        // Attempt to connect
        // You can change "NodeMCUClient" to any unique client ID NodeMCUClient
        if (client.connect("mqtt:topic:616a0f5e1e:Thing2")) {
            Serial.println("connected");
            
            // Subscribe to the topic
            client.subscribe(mqtt_topic);
            Serial.print("Subscribed to: ");
            Serial.println(mqtt_topic);
            
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

// MQTT message callback function
void callback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    
    // Convert payload to string
    String message = "";
    for (int i = 0; i < length; i++) {
        message += (char)payload[i];
    }
    Serial.println(message);
    
    // Control LED based on message
    if (message == "1") {
        digitalWrite(ledPin, LOW);  // Turn ON LED (inverted logic)
        Serial.println("LED turned ON");
    } 
    else if (message == "0") {
        digitalWrite(ledPin, HIGH); // Turn OFF LED (inverted logic)
        Serial.println("LED turned OFF");
    }
    else {
        Serial.println("Unknown message received");
    }
}

void setup() {
    Serial.begin(115200);
    setup_wifi();
    client.setServer(mqtt_server, mqtt_port);
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH); // Turn off initially (inverted logic)
    client.setCallback(callback);

    pinMode(D0, INPUT);
}
/***
    3V to button pin 1 
    resistor to button pin 2
    GND to resistor other pin 2
    D0 to Button register junction
*/
int prevState = 0;
unsigned long lastMsg = 0;
void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
    
    // Your logic to publish messages
    // client.publish(mqtt_topic, "0");

    int currentState = digitalRead(D0);
    if(prevState == 0 && currentState == 1) 
    {
        int ledState = digitalRead(ledPin);
        digitalWrite(ledPin, !ledState);   
    }
    prevState = currentState;

    // To eastablish delay without freeze other activity
    unsigned long now = millis();
    if(now - lastMsg > 5000)
    {
        lastMsg = now;
    
        /***
            Dummy Temp Humid sensor
        */
        float temparature = random(25, 35);
        float humidity = random(50, 80);
        char tempString[8];
        char humidString[8];
        /***
            d_to_strf
            dtostrf(temperature, 1, 2, tempString);
            temperature: The float variable to convert 
            1 (Width): The minimum total width. If the number is wider, this value is ignored; it does not truncate integer digits.
            2 (Precision): The exact number of digits after the decimal point.
            tempString: The destination character array (buffer) where the result is stored.
        */
        dtostrf(temparature, 1, 2, tempString);
        dtostrf(humidity, 1, 2, humidString);

        // Publish to MQTT
        client.publish("device/temp", tempString);
        client.publish("device/humid", humidString);
    }
}

