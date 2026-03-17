#include "model.h"

Eloquent::ML::Port::DecisionTree mymodel;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  /**
    * Potentiometer middle pin to D0
  */
  int sensorValue = analogRead(D0);
  Serial.println(sensorValue);  

  float input[] = {(float) sensorValue};

  int prediction = mymodel.predict(input);
  if(prediction == 1)
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  else
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }

  delay(200);  // delay in between reads for stability
}
