#include <Robot.h>

#include "Enes100.h"

Robot tankTesting;


void setup() {
    tankTesting.tankSetup();

    // Initialize Enes100 Library
    // Team Name, Mission Type, Marker ID, TX Pin, RX Pin
    Enes100.begin("Sieze the data", DATA, 11, TANK_WIFI_TX, TANK_WIFI_RX);
    tankTesting.moveLinear(5, 0.8); //move forward 5 in at 0.8
    tankTesting.moveLinear(5, -0.8); //move backward 5 in at 0.8
    tankTesting.spin(90, 0.8); //turn right 90 degrees at 0.8
    tankTesting.spin(-90, 0.8); //turn left 90 degrees at 0.8  
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
