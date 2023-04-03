#ifndef UltraSensor_h
#define UltraSensor_h

#include <Arduino.h>


class Robot {

    public:
        int trigPin;
        int echoPin;
        int distanceToCheck;

        UltraSensor(int trigPin, int echoPin, double distance);
        bool isObjectBlocking();

};

#endif