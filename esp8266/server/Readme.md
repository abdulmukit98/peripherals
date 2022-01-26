
```
#include<ESP8266WiFi.h>

int led = D4;
WiFiServer server(80);
IPAddress ip(192, 168, 0, 20);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);

String ssid = "Smart";
String pass = "menthokol";

String readString;
String status = "on";

void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    
    WiFi.config(ip, gateway, subnet);
    WiFi.begin(ssid, pass);
    while(WiFi.status() != WL_CONNECTED)
    {
      Serial.print(".");
      delay(500);
    }
    server.begin();

    Serial.println();
    Serial.print("Server is at ");
    Serial.println(WiFi.localIP());
}

void loop() {
    // listening from incoming client
    WiFiClient client = server.available();

    if(client)
    {
        Serial.println("New client");
        while(client.connected())
        {
            if(client.available())
            {
                char c = client.read();
                //Serial.print(c);

                readString += c;

                // receive a complete request
                // reset webpage and work
                if(c == '\n')
                {
                    Serial.println(readString);
                    client.println("HTTP/1.1 200 OK");
                    client.println("Connection-Type: text/html");
                    client.println("Connection: close");
                    client.println("Refresh: 3");
                    client.println();

                    client.println("<!DOCTYPE html>");
                    client.println("<html>");
                    client.println("<head>");
                    client.println("<title> Haleon </title>");
                    client.println("</head>");
                    
                    client.println("<body style = background-color:orange>");
                   
                    client.println("<a href = \" btnon-on  \" > <button> Button on </button> </a>");
                    client.println("<a href = \" btnoff-off \" > <button> Button off </button> </a> ");
                    
                    client.print("<p> Analog Read A0 = ");
                    int sensor = analogRead(A0);
                    client.print(sensor);
                    client.println(" </p> <br>");

                    
                    client.println("</body>");
                    client.println("</html>");
                    client.println();

                    delay(1);
                    client.stop();
                    
                    if(readString.indexOf("btnon") > 0)
                        digitalWrite(led, LOW);
                    if(readString.indexOf("btnoff") > 0)
                        digitalWrite(led, HIGH);
                   
                    readString = "";
                    
                }
            }
          
        }
    }
    

}
```

