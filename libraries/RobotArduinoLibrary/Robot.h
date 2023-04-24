#ifndef Robot_h
#define Robot_h

#include <Arduino.h>


#define TANK_WIFI_TX 52
#define TANK_WIFI_RX 50

#define TANK_MOTOR_1_FORWARD 11 //LF
#define TANK_MOTOR_1_REVERSE 10 //LF
#define TANK_MOTOR_2_FORWARD 9 //LB
#define TANK_MOTOR_2_REVERSE 8 //LB
#define TANK_MOTOR_3_FORWARD 4 //RF
#define TANK_MOTOR_3_REVERSE 5 //RF
#define TANK_MOTOR_4_FORWARD 2 //RB
#define TANK_MOTOR_4_REVERSE 3 //RB







class Robot {

    public:
        int leftFrontMotorForwardPin;
        int rightFrontMotorForwardPin;
        int rightBackMotorForwardPin;
        int leftBackMotorForwardPin;
        int leftFrontMotorReversePin;
        int rightFrontMotorReversePin;
        int rightBackMotorReversePin;
        int leftBackMotorReversePin;
        int leftMotorAnalogPin;
        int rightMotorAnalogPin;
        bool isTank;

        int robotForwardConstant;
        int robotBackwardConstant;
        int robotLeftConstant;
        int robotRightConstant;

        int tankForwardConstant;
        int tankBackwardConstant;
        int tankLeftConstant;
        int tankRightConstant;


        Robot();
        //power is from -1 to 1, will convert to -255 to 255
        //degrees start at 0 at vertical on robot, left is negative, right is positive
        //on robot: back (-) to front (+) of robot is y axis
        void setPins2Motor(int leftF, int leftR, int leftA, int rightF, int rightR, int rightA);
        void tankSetup();
        void turnOffMotors();
        void moveLinear(double distance, double power);
        void spin(double degrees, double power);
};

#endif