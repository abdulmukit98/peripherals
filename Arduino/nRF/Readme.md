```
#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
#include <printf.h>

/**
 * CE, CSN - Standby or Active mode
 * Transmit or Command mode
 *  
 * SPI pin  
 * MOSI - 11
 * SCK  - 13
 * MISO - 12
 */
RF24 radio(7, 8);   //  CE, CSN
const byte address[6] = "00001";

void setup()
{
  radio.begin();
  radio.setPALevel(RF24_PA_LOW);

  radio.openWritingPipe(address);
  radio.stopListening();

  Serial.begin(9600);
  printf_begin();
  radio.printDetails();
}

void loop() {
   


}

```


```
[code]
#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
#include <printf.h>

/**
 * CE, CSN - Standby or Active mode
 * Transmit or Command mode
 *  
 * SPI pin  
 * MOSI - 11
 * SCK  - 13
 * MISO - 12
 */
RF24 radio(7, 8);   //  CE, CSN
const byte address[6] = "Node1";

void setup()
{
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  Serial.begin(9600);
  printf_begin();
  radio.printDetails();
}

void loop() {
   const char text[] = "Hello World";
   radio.write(&text, sizeof(text));
   Serial.println("sent");
   delay(1000);


}
```
