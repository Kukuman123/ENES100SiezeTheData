#include "UltraSensor.h"

UltraSensor::UltraSensor(int trigPin, int echoPin){
    this.trigPin = trigPin;
    this.echoPin = echoPin;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT)
};
//meters
bool UltraSensor::isObjectBlocking(double distanceToCheck){
    //Clear trigPin
    digitalWrite(this.trigPin, LOW);
    delayMicroseconds(5);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(this.trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this.trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    long duration = pulseIn(this.echoPin, HIGH);
    // Calculating the distance
    double distance = ((duration/2)/74)/100;
    // Prints the distance on the Serial Monitor
    if(distance > distanceToCheck){
        return false;
    }
    else{
        return true;
    }
};