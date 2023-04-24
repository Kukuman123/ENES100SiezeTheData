#include <Servo.h>

#include <Enes100.h>

#include "Robot.h"


Robot robotTesting;
int duty1 = A1;
int duty2 = A2;
int hallSensorPin = 12;
int hallsensorValue = 0;
Servo myServo;

void setup() {
  Enes100.begin("Sieze the data", DATA, 8, A4, A3);
    delay(500);

    
    Enes100.ping();
    //robotTesting.setPins2Motor(7,8,9,4,5,3);
    //robotTesting.moveLinear(1, 0.8);
    myServo.attach(A5);
    for (int pos = 0; pos <= 360; pos += 1) { // goes from 0 degrees to 360 degrees
    // in steps of 1 degree
      myServo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
    }
    //robotTesting.moveLinear(some distance, 0.8);
    for (int pos = 360; pos >= 0; pos = pos - 1) { // goes from 180 degrees to 0 degrees
      myServo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
    }
    //robotTesting.moveLinear(-smol distance, 0.8);
    pinMode(12, INPUT);
    hallsensorValue = digitalRead(hallSensorPin);
    delay(500);
    if(hallsensorValue>1){
        Enes100.println("True");
    }

    pinMode(A1, INPUT);
    pinMode(A2, INPUT);

    int dutyCycle = (analogRead(duty1) + analogRead(duty2))/2;
    delay(10);
    double realDutyCycle = ((double)dutyCycle)/1023;
    if(realDutyCycle > 0.85){
        Enes100.mission(CYCLE, 90);
    }
    else if(realDutyCycle > 0.65){
        Enes100.mission(CYCLE, 70);
    }
    else if(realDutyCycle > 0.45){
        Enes100.mission(CYCLE, 50);
    }
    else if(realDutyCycle > 0.25){
        Enes100.mission(CYCLE, 30);
    }
    else{
        Enes100.mission(CYCLE, 10);
    }
    //robotTesting.moveLinear(smol distance, 0.8);
    for (int pos = 0; pos <= 360; pos += 1) { // goes from 0 degrees to 360 degrees
    // in steps of 1 degree
      myServo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15 ms for the servo to reach the position
    }
    //robotTesting.moveLinear(-some distance, 0.8);
    for (int pos = 360; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myServo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 15 ms for the servo to reach the position
    }
}

void loop() {
  // put your main code here, to run repeatedly:

}
