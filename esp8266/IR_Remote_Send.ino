#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = D5;   // GPIO4
const int ledPin = LED_BUILTIN;

IRsend irsend(kIrLed);

void setup() {
  Serial.begin(115200);
  irsend.begin();
  Serial.println("IR Transmitter Ready...");
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

// 0x0x3D00FF OFF
// 0x0x3D807F Mute

void loop() {

  Serial.println("Sending IR Code...");
  
  // Send NEC code
  irsend.sendNEC(0x3D00FF, 32);  // 32 bits for NEC
  
  // Blink for 100ms
  digitalWrite(ledPin, LOW);
  delay(100);
  digitalWrite(ledPin, HIGH);
  
  delay(1200);  // send every 5 seconds
}
