// WiFi_Scanner.ino
#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\nWiFi Scanner Started");
  Serial.println("-------------------");
  
  // Set WiFi to station mode
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop() {
  // Scan for networks
  int networks = WiFi.scanNetworks();
  
  Serial.println("\nScan complete!");
  
  if (networks == 0) {
    Serial.println("No networks found");
  } else {
    Serial.print("Found ");
    Serial.print(networks);
    Serial.println(" networks:");
    
    // Print each network
    for (int i = 0; i < networks; i++) {
      Serial.print(i + 1);
      Serial.print(". ");
      Serial.print(WiFi.SSID(i));           // Network name
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));           // Signal strength
      Serial.print(" dBm)");
      
      // Show encryption type
      if (WiFi.encryptionType(i) == ENC_TYPE_NONE) {
        Serial.println(" [Open]");
      } else {
        Serial.println(" [Secured]");
      }
    }
  }
  
  // Clean up and wait
  WiFi.scanDelete();
  delay(5000);
}
