#include "UltraSensor.h"

UltraSensor::UltraSensor(int trigPin, int echoPin){
    UltraSensor::trig = trigPin;
    UltraSensor::echo = echoPin;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}
//meters
bool UltraSensor::isObjectBlocking(double distanceToCheck){
    //Clear trigPin
    digitalWrite(UltraSensor::trig, LOW);
    delayMicroseconds(5);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(UltraSensor::trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(UltraSensor::trig, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    long duration = pulseIn(UltraSensor::echo, HIGH);
    // Calculating the distance
    double distance = ((duration/2)/74)/100;
    UltraSensor::distanceInfo = distance;
    // Prints the distance on the Serial Monitor
    if(distance > distanceToCheck){
        return false;
    }
    else{
        return true;
    }
}

String UltraSensor::sendInfo(){
    String returnInfo = (String)UltraSensor::distanceInfo;
    return returnInfo;
}