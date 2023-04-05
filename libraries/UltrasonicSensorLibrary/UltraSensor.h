#ifndef UltraSensor_h
#define UltraSensor_h

#include <Arduino.h>


class Robot {

    public:
        int trigPin;
        int echoPin;

        UltraSensor(int trigPin, int echoPin);
        bool isObjectBlocking(double distanceToCheck);

};

#endif