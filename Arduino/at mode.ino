
#include <SoftwareSerial.h>
 
SoftwareSerial Bluetooth(8,9);    // 8- tx  9- rx

/*
    Serial monitor 9600  baud
    both nl and clear
    
    +5V to en
    while pressing hc05 butten then power to enter at+command mode
*/
 
void setup() {
  Serial.begin(9600);
  Bluetooth.begin(38400);
}
 
void loop() {
  while (Serial.available()) {
      delay(1);
      Bluetooth.write(Serial.read());
  }
  while (Bluetooth.available()) {
       Serial.write(Bluetooth.read());
  }
}
