#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int counter = 0;

// SDA = D2
// SCL = D1
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display
void setup() {
  lcd.init();                       // Initialize the LCD
  lcd.backlight();                  // Turn on the backlight
  lcd.clear();                      // Clear the LCD screen
}
void loop() {
  lcd.setCursor(0, 0);               // Set the cursor to the first column and first row
  lcd.print("Hello World");     // Print some text
  lcd.setCursor(0,1);
  lcd.print(counter);
  counter = counter + 1;
  delay(500);                        // Wait for 1/2 seconds
}

// #include <Wire.h>
// void setup() {
//   Serial.begin (9600);
//   Serial.println ("I2C scanner. Scanning ...");
//   byte count = 0;
//   // 0x27 0x3F
//   Wire.begin();
//   for (byte i = 8; i < 120; i++)
//   {
//     Wire.beginTransmission (i);
//     if (Wire.endTransmission () == 0)
//       {
//       Serial.print ("Found address: ");
//       Serial.print (i, DEC);
//       Serial.print (" (0x");
//       Serial.print (i, HEX);
//       Serial.println (")");
//       count++;
//       delay (1);
//       }
//   }
//   Serial.println ("Done.");
//   Serial.print ("Found ");
//   Serial.print (count, DEC);
//   Serial.println (" device(s).");
// }  // end of setup

// void loop() {}
