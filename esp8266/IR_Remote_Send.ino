#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = D5;   // GPIO4

IRsend irsend(kIrLed);

void setup() {
  Serial.begin(115200);
  irsend.begin();
  Serial.println("IR Transmitter Ready...");
}

void loop() {

  Serial.println("Sending IR Code...");
  
  // Send NEC code
  irsend.sendNEC(0x3D30CF, 32);  // 32 bits for NEC
  
  delay(5000);  // send every 5 seconds
}
