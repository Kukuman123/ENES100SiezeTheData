#ifndef UltraSensor_h
#define UltraSensor_h

#include <Arduino.h>


class UltraSensor{

    public:
        int trig;
        int echo;
        double distanceInfo;

        UltraSensor(int trigPin, int echoPin);
        bool isObjectBlocking(double distanceToCheck);
        String sendInfo();

};

#endif