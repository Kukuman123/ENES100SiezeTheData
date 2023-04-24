#include <Servo.h>
#include <Robot.h>
#include <math.h>
#include "Enes100.h"
#include <UltraSensor.h>

Servo myServo;
int pos = 0;

Robot robotTesting;
//Robot robotTesting; 8, 7, 9, 5, 4, 3
UltraSensor objectDetection(10, 11);
int duty1 = A1;
int duty2 = A2;
int hallSensorPin = 12;
int hallsensorValue = 0;






void setup() {



    /*myServo.attach(A5);
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
    }*/








    /*pinMode(12, INPUT);
    hallsensorValue = digitalRead(hallSensorPin);
    if(hallsensorValue>1){
        Serial.println("True");
    }*/
    /*pinMode(A1, INPUT);
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
    }*/








    int lengthFromCenter = 0.1225;
    bool cheatTheSystem = false;
    int topMiddleBottom = 0.1;
    //robotTesting.tankSetup();
    robotTesting.setPins2Motor(7, 8, 9, 4, 5, 3);

    // Initialize Enes100 Library
    // Team Name, Mission Type, Marker ID, TX Pin, RX Pin
    Enes100.begin("Sieze the data", DATA, 8, A4, A3);
    delay(2500);

    while (!Enes100.updateLocation()) {
        // OSV's location was not found
        Enes100.println("404 Not Found");
    }

    double initialX = Enes100.location.x;
    double initialY = Enes100.location.y;
    double initialAng = Enes100.location.theta;
    Enes100.print("X: ");
    Enes100.print(initialX);
    Enes100.print("Y: ");
    Enes100.print(initialY);
    Enes100.print("Theta: ");
    Enes100.print(initialAng);
    

    bool topLocationTrue = true;
    topMiddleBottom = 1;
    if(abs(initialY-0.55) <= 0.1){
        topLocationTrue = false;
        topMiddleBottom = 3;
    }

    double rotateAngle = initialAng * (180/M_PI);
        // if at top spin to face down 
    if(topLocationTrue) {
        rotateAngle = rotateAngle + 90;
        robotTesting.spin(rotateAngle, 0.8);
        robotTesting.moveLinear(0.75, 0.8);
    } else {
    // if at bottom spin to face up 
        rotateAngle = rotateAngle - 90;
        robotTesting.spin(rotateAngle, 0.8);
        robotTesting.moveLinear(0.75, 0.8);
    }
    Enes100.print("done");
    delay(1000);
    robotTesting.moveLinear(-0.75, 0.8);
    if(topLocationTrue){
        spin(-90, 0.8);
    }
    else{
        spin(90, 0.8);
    }

    if(cheatTheSystem){
        robotTesting.spin(-90, 0.8);
        robotTesting.moveLinear((0.54-lengthFromCenter) + (0.5*(topMiddleBottom-1)), 0.8);
        robotTesting.spin(90, 0.8);
        while(Enes100.location.x <= 3.7){
            robotTesting.move(0.8);
            Enes100.updateLocation();
        }
        robotTesting.turnOffMotors();


    }
    else{
        if(topLocationTrue){
            //
            robotTesting.moveLinear(0.84-lengthFromCenter, 0.8);
            delay(500);
            while(objectDetection.isObjectBlocking(0.03)){
                Enes100.print(objectDetection.sendInfo());
                robotTesting.moveLinear(0.2, -0.8);
                robotTesting.turnOffMotors();
                robotTesting.spin(90, 0.8);
                robotTesting.turnOffMotors();
                robotTesting.moveLinear(0.5, 0.8);
                robotTesting.turnOffMotors();
                robotTesting.spin(-90, 0.8);
                robotTesting.turnOffMotors();
                robotTesting.moveLinear(0.2, 0.8);
                robotTesting.turnOffMotors();
                topMiddleBottom = topMiddleBottom + 1;
                delay(500);
            }
            robotTesting.moveLinear(0.6, 0.8);
            robotTesting.turnOffMotors();
            robotTesting.spin(-90, 0.8);
            robotTesting.turnOffMotors();
            robotTesting.moveLinear(0.5*(topMiddleBottom-1), 0.8);
            robotTesting.turnOffMotors();
            robotTesting.spin(90, 0.8);
            robotTesting.turnOffMotors();
            robotTesting.moveLinear(0.2, 0.8);
            robotTesting.turnOffMotors();
            delay(500);
            while(objectDetection.isObjectBlocking(0.03)){
                robotTesting.moveLinear(0.2, -0.8);                
                robotTesting.spin(90, 0.8);
                robotTesting.moveLinear(0.5, 0.8);
                robotTesting.spin(-90, 0.8);
                robotTesting.moveLinear(0.2, 0.8);
                topMiddleBottom = topMiddleBottom + 1;
                delay(500);
            }
            robotTesting.moveLinear(0.7, 0.8);
            robotTesting.spin(-90, 0.8);
            robotTesting.moveLinear(0.5*(topMiddleBottom-1), 0.8);
            robotTesting.spin(90, 0.8);
            delay(500);
            Enes100.updateLocation();
            while(Enes100.location.x <= 3.7){
                robotTesting.move(0.8);
                Enes100.updateLocation();
            }
            robotTesting.turnOffMotors();
            
        }
        else{
            robotTesting.moveLinear(0.84-lengthFromCenter, 0.8);
            delay(500);
            while(objectDetection.isObjectBlocking(0.03)){
                robotTesting.moveLinear(0.2, -0.8);
                robotTesting.spin(-90, 0.8);
                robotTesting.moveLinear(0.5, 0.8);
                robotTesting.spin(90, 0.8);
                robotTesting.moveLinear(0.2, 0.8);
                topMiddleBottom = topMiddleBottom - 1;
                delay(500);
            }
            robotTesting.moveLinear(0.6, 0.8);
            robotTesting.spin(90, 0.8);
            robotTesting.moveLinear(0.5*(3-topMiddleBottom), 0.8);
            robotTesting.spin(-90, 0.8);
            robotTesting.moveLinear(0.2, 0.8);
            delay(500);
            while(objectDetection.isObjectBlocking(0.03)){
                robotTesting.moveLinear(0.2, -0.8);
                robotTesting.spin(-90, 0.8);
                robotTesting.moveLinear(0.5, 0.8);
                robotTesting.spin(90, 0.8);
                robotTesting.moveLinear(0.2, 0.8);
                topMiddleBottom = topMiddleBottom - 1;
                delay(500);
            }
            robotTesting.moveLinear(0.7, 0.8);
            robotTesting.spin(-90, 0.8);
            robotTesting.moveLinear(0.5*(topMiddleBottom-1), 0.8);
            robotTesting.spin(90, 0.8);
            delay(500);
            Enes100.updateLocation();
            while(Enes100.location.x <= 3.7){
                robotTesting.move(0.8);
                Enes100.updateLocation();
            }
            robotTesting.turnOffMotors();
        }
    }

  Enes100.print("done");

}

void loop(){

}
