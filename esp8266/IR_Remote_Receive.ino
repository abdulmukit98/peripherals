#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t kRecvPin = D5;   // GPIO14

IRrecv irrecv(kRecvPin);
decode_results results;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("IR Receiver Ready...");
  
  irrecv.enableIRIn();  // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    
    Serial.println("IR Signal Received!");
    
    // Print HEX code
    Serial.print("HEX Code: 0x");
    Serial.println(resultToHexidecimal(&results));
    
    // Print protocol type
    Serial.print("Protocol: ");
    Serial.println(typeToString(results.decode_type));
    
    Serial.println("-----------------------");

    irrecv.resume();  // Receive next signal
  }
}
