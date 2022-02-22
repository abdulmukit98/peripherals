
#include<Keypad.h>
// byte is an unsigned integer
byte led = 13;

/** array bound must be a constant
 *  
 *  Note that we assign a strng "1234" in char array
 *  only then we need an extra null bit
 *  
 *  if we decalre an array of char array
 *  we dont need extra null bit then
 *  
 *  null bit only applicable to string
 */
#define psize 5
char okpass[psize] = "1249", ipass[psize];   


const byte row = 4, col = 4;
char keymap[row][col] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'} 
};

byte rpins[row] = {12, 11, 10, 9};
byte cpins[col] = {8, 7, 6, 5};

Keypad mypad = Keypad( makeKeymap(keymap),
                     rpins, cpins,
                     row, col
                    );
void setup() {

  Serial.begin(9600);
  Serial.print("okpass: ");
  Serial.println(okpass);
}

byte i=0;
void loop() {

  char key = mypad.getKey();
  if(key != NULL)
  {
      Serial.println(key);
      ipass[i] = key;
      i = i+1;
  }

  if(i == psize-1)
  {
    if(strcmp(okpass, ipass) == 0)
    {
        // accepted
        Serial.println("accepted");
    }
    else{
      Serial.println("rejected");
    }
    i = 0;
  }

  
}




