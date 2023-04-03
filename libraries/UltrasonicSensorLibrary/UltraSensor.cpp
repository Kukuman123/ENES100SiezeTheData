#include "UltraSensor.h"

UltraSensor::UltraSensor(int trigPin, int echoPin, double distance){
    this.trigPin = trigPin;
    this.echoPin = echoPin;
    this.distanceToCheck = distance;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT)
};

bool UltraSensor::isObjectBlocking(){
    //Clear trigPin
    digitalWrite(this.trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(this.trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this.trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    long duration = pulseIn(this.echoPin, HIGH);
    // Calculating the distance
    double distance = duration * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    if(distance > this.distanceToCheck){
        return false;
    }
    else{
        return false;
    }
};