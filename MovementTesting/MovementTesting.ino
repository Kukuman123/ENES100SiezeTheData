#include <Robot.h>
#include <math.h>
#include "Enes100.h"
#include <UltraSensor.h>

Robot tankTesting;
Robot robotTesting; //8, 7, 9, 5, 4, 3
UltraSensor objectDetection(18, 19, 0.03)



void setup() {
    tankTesting.tankSetup();
    //robotTesting.setPins2Motor(8, 7, 9, 5, 4, 3);

    // Initialize Enes100 Library
    // Team Name, Mission Type, Marker ID, TX Pin, RX Pin
    Enes100.begin("Sieze the data", DATA, 11, TANK_WIFI_TX, TANK_WIFI_RX);
    delay(500);

    while (!Enes100.updateLocation()) {
        // OSV's location was not found
        Enes100.println("404 Not Found");
    }

    double initialX = Enes100.location.x;
    double initialY = Enes100.location.y;
    double initialAng = Enes100.location.theta;

    bool topLocationTrue = true;
    if((intialY - 0.55) < (1.45 - initialY)){
        topLocationTrue = false;
    }

    double rotateAngle = intialAng * (180/M_PI);
    tankTesting.spin(rotateAngle, 0.8);

    tankTesting.moveLinear(0.92, 0.8);
    if()










    //tankTesting.moveLinear(0.25, 0.8); //move forward 0.25 m at 0.8
    // tankTesting.moveLinear(5, -0.8); //move backward 0.25 m at 0.8
    // tankTesting.spin(90, 0.8); //turn right 90 degrees at 0.8
    // tankTesting.spin(-90, 0.8); //turn left 90 degrees at 0.8
}

void loop() {

    // Update the OSV's current location
    while (!Enes100.updateLocation()) {
        // OSV's location was not found
        Enes100.println("404 Not Found");
    }
    Enes100.print("OSV is at (");
    Enes100.print(Enes100.location.x);
    Enes100.print(", ");
    Enes100.print(Enes100.location.y);
    Enes100.print(", ");
    Enes100.print(Enes100.location.theta);
    Enes100.println(")");

}
