#include <Robot.h>
#include <math.h>
#include "Enes100.h"
#include <UltraSensor.h>

Robot tankTesting;
//Robot robotTesting; 8, 7, 9, 5, 4, 3
UltraSensor objectDetection(18, 19);






void setup() {
  int lengthFromCenter = 0.12;
  bool cheatTheSystem = false;
  int topMiddleBottom = 0.1;
    tankTesting.tankSetup();
    //robotTesting.setPins2Motor(8, 7, 9, 5, 4, 3);

    // Initialize Enes100 Library
    // Team Name, Mission Type, Marker ID, TX Pin, RX Pin
    Enes100.begin("Sieze the data", DATA, 11, TANK_WIFI_TX, TANK_WIFI_RX);
    delay(5000);

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
    tankTesting.spin(rotateAngle, 0.8);
    Enes100.print("done");
    delay(1000);

    if(cheatTheSystem){
        tankTesting.spin(-90, 0.8);
        tankTesting.moveLinear((0.54-lengthFromCenter) + (0.5*(topMiddleBottom-1)), 0.8);
        tankTesting.spin(90, 0.8);
        while(Enes100.location.x <= 3.7){
            tankTesting.move(0.8);
            Enes100.updateLocation();
        }
        tankTesting.turnOffMotors();


    }
    else{
        if(topLocationTrue){
            tankTesting.moveLinear(0.84-lengthFromCenter, 0.8);
            delay(500);
            while(objectDetection.isObjectBlocking(0.03)){
                Enes100.print(objectDetection.sendInfo());
                tankTesting.moveLinear(0.2, -0.8);
                tankTesting.turnOffMotors();
                tankTesting.spin(90, 0.8);
                tankTesting.turnOffMotors();
                tankTesting.moveLinear(0.5, 0.8);
                tankTesting.turnOffMotors();
                tankTesting.spin(-90, 0.8);
                tankTesting.turnOffMotors();
                tankTesting.moveLinear(0.2, 0.8);
                tankTesting.turnOffMotors();
                topMiddleBottom = topMiddleBottom + 1;
                delay(500);
            }
            tankTesting.moveLinear(0.6, 0.8);
            tankTesting.turnOffMotors();
            tankTesting.spin(-90, 0.8);
            tankTesting.turnOffMotors();
            tankTesting.moveLinear(0.5*(topMiddleBottom-1), 0.8);
            tankTesting.turnOffMotors();
            tankTesting.spin(90, 0.8);
            tankTesting.turnOffMotors();
            tankTesting.moveLinear(0.2, 0.8);
            tankTesting.turnOffMotors();
            delay(500);
            while(objectDetection.isObjectBlocking(0.03)){
                tankTesting.moveLinear(0.2, -0.8);                
                tankTesting.spin(90, 0.8);
                tankTesting.moveLinear(0.5, 0.8);
                tankTesting.spin(-90, 0.8);
                tankTesting.moveLinear(0.2, 0.8);
                topMiddleBottom = topMiddleBottom + 1;
                delay(500);
            }
            tankTesting.moveLinear(0.7, 0.8);
            tankTesting.spin(-90, 0.8);
            tankTesting.moveLinear(0.5*(topMiddleBottom-1), 0.8);
            tankTesting.spin(90, 0.8);
            delay(500);
            Enes100.updateLocation();
            while(Enes100.location.x <= 3.7){
                tankTesting.move(0.8);
                Enes100.updateLocation();
            }
            tankTesting.turnOffMotors();
            
        }
        else{
            tankTesting.moveLinear(0.84-lengthFromCenter, 0.8);
            delay(500);
            while(objectDetection.isObjectBlocking(0.03)){
                tankTesting.moveLinear(0.2, -0.8);
                tankTesting.spin(-90, 0.8);
                tankTesting.moveLinear(0.5, 0.8);
                tankTesting.spin(90, 0.8);
                tankTesting.moveLinear(0.2, 0.8);
                topMiddleBottom = topMiddleBottom - 1;
                delay(500);
            }
            tankTesting.moveLinear(0.6, 0.8);
            tankTesting.spin(90, 0.8);
            tankTesting.moveLinear(0.5*(3-topMiddleBottom), 0.8);
            tankTesting.spin(-90, 0.8);
            tankTesting.moveLinear(0.2, 0.8);
            delay(500);
            while(objectDetection.isObjectBlocking(0.03)){
                tankTesting.moveLinear(0.2, -0.8);
                tankTesting.spin(-90, 0.8);
                tankTesting.moveLinear(0.5, 0.8);
                tankTesting.spin(90, 0.8);
                tankTesting.moveLinear(0.2, 0.8);
                topMiddleBottom = topMiddleBottom - 1;
                delay(500);
            }
            tankTesting.moveLinear(0.7, 0.8);
            tankTesting.spin(-90, 0.8);
            tankTesting.moveLinear(0.5*(topMiddleBottom-1), 0.8);
            tankTesting.spin(90, 0.8);
            delay(500);
            Enes100.updateLocation();
            while(Enes100.location.x <= 3.7){
                tankTesting.move(0.8);
                Enes100.updateLocation();
            }
            tankTesting.turnOffMotors();
        }
    }

  Enes100.print("done");

}

void loop(){

}
