#include <SoftwareSerial.h>

/***
  * HC05 TX <=> NodeMCU D7
  * HC05 RX <=> NodeMCU D6 Via resistor
*/

// RX, TX
SoftwareSerial bt(D7, D6);  // D7 = RX, D6 = TX

const int ledPin = LED_BUILTIN;  // Built-in LED (GPIO2 or GPIO16 depending board)

void setup() {
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
  bt.begin(9600);  // HC-05 default baud rate

  digitalWrite(ledPin, HIGH); // OFF (NodeMCU LED is inverted)

  Serial.println("Bluetooth LED Control Ready");
}

void loop() {

  if (bt.available()) {
    char command = bt.read();
    Serial.println(command);

    if (command == '1') {
      digitalWrite(ledPin, LOW);  // ON (inverted logic)
      Serial.println("LED ON");
    }
    else if (command == '0') {
      digitalWrite(ledPin, HIGH); // OFF
      Serial.println("LED OFF");
    }
  }

}
