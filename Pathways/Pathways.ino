#include <Robot.h> 
#include <math.h>
#include "Enes100.h"
#include <UltraSensor.h>

Robot tankTesting; 
//Robot robotTesting;

void setup() { 
    //change to robotTesting.robotSetup(); when testing robot
    tankTesting.tankSetup();
    Enes100.begin("Sieze the data", DATA, 11, TANK_WIFI_TX, TANK_WIFI_RX); 
    delay(500); 

    while (!Enes100.updateLocation()) {
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
    
    // check if were at top or bottom
    bool topLocationTrue = true;
    if(abs(initialY-0.55) <= 0.1){
        topLocationTrue = false;
    }
    
    
    double rotateAngle = initialAng * (180/M_PI);
        // if at top spin to face down 
    if(topLocationTrue) {
        rotateAngle = rotateAngle + 90;
        tankTesting.spin(rotateAngle, 0.8);
        tankTesting.moveLinear(0.75, 0.8);
    } else {
    // if at bottom spin to face up 
        rotateAngle = rotateAngle + 90;
        tankTesting.spin(-rotateAngle, 0.8);
        tankTesting.moveLinear(0.75, 0.8);
    }
    Enes100.print("done");
    delay(1000);

}

void loop() {
  
}