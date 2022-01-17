#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "techshopju-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "uxzCFIynuAb3bsSY3tlnWf31u184BtmpazrnyJa0"
#define WIFI_SSID "Smart"
#define WIFI_PASSWORD "menthokol"

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(D4, OUTPUT);
}


void loop() {

  String s = Firebase.getString("why");
  if(s == "on")
  {
    digitalWrite(D4, 0);
  }
  if(s == "off")
  {
    digitalWrite(D4, 1);
  }

  delay(1000);
}
