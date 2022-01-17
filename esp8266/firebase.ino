
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "techshopju-default-rtdb.firebaseio.com"      // Realtime database website
#define FIREBASE_AUTH "uxzCFIynuAb3bsSY3tlnWf31u184BtmpazrnyJa0"    // database secret key
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
}


void loop() {
  
  /**
   *  Need after set or update value
   * // handle error
   * if (Firebase.failed()) {
   *   Serial.print("pushing /logs failed:");
   *   Serial.println(Firebase.error());  
   *   return;
   * }
   */
  

  // set value
  Firebase.setFloat("number", 42.0);
  delay(1000);


  // update value
  Firebase.setFloat("number", 43.0);
  delay(1000);
  
  
  // get value 
  Serial.print("number: ");
  Serial.println(Firebase.getFloat("number"));
  delay(1000);
  
  
  // remove value
  Firebase.remove("number");
  delay(1000);
  
  
  // set string value
  Firebase.setString("message", "hello world");
  
  
  // set bool value
  Firebase.setBool("truth", false);
  
  
}

