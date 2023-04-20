#include <Robot.h>


void setup() {
  pinMode(8 ,OUTPUT);
  pinMode(7 ,OUTPUT);
  pinMode(9 ,OUTPUT);
  pinMode(5 ,OUTPUT);
  pinMode(4 ,OUTPUT);
  pinMode(3 ,OUTPUT);
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    analogWrite(9, 0.8*255);

    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    analogWrite(3, 0.8*355);

}

void loop() {
  // put your main code here, to run repeatedly:

}
