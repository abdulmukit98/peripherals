/**
 * for arduino due use Serial1, Serial2, Serial3  instead of SoftwareSerial
 #define blue Serial1
 */
#include <SoftwareSerial.h>
SoftwareSerial blue(8,9); // BT(Tx,Rx)

char data;                //Variable for storing Incoming_value
void setup() 
{
  blue.begin(9600);
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(13, OUTPUT);        //Sets digital pin 13 as output pin
}
void loop()
{
  if(blue.available() > 0)  
  {
    data = blue.read();      //Read the incoming data and store it into variable Incoming_value
    Serial.print(data);        //Print Value of Incoming_value in Serial monitor
    Serial.print("\n");        //New line 
    if(data == '1')            //Checks whether value of Incoming_value is equal to 1 
      digitalWrite(13, HIGH);  //If value is 1 then LED turns ON
    else if(data == '0')       //Checks whether value of Incoming_value is equal to 0
      digitalWrite(13, LOW);   //If value is 0 then LED turns OFF
  }                            
 
}              
