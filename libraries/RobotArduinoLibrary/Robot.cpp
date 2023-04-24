#include "Robot.h"


Robot::Robot(){
    isTank = false;
}



void Robot::setPins2Motor(int leftF, int leftR, int leftA, int rightF, int rightR, int rightA){
    leftFrontMotorForwardPin = leftF;
    leftFrontMotorReversePin = leftR;

    rightFrontMotorForwardPin = rightF;
    rightFrontMotorReversePin = rightR;

    rightMotorAnalogPin = rightA;
    leftMotorAnalogPin = leftA;

    robotBackwardConstant = 5000;
    robotForwardConstant = 5000;
    robotLeftConstant = 25;
    robotRightConstant = 25;

    isTank = false;

    pinMode(leftFrontMotorForwardPin, OUTPUT);
    pinMode(leftFrontMotorReversePin, OUTPUT);
    pinMode(rightFrontMotorForwardPin, OUTPUT);
    pinMode(rightFrontMotorReversePin, OUTPUT);
    pinMode(leftMotorAnalogPin, OUTPUT);
    pinMode(rightMotorAnalogPin, OUTPUT);
}

void Robot::tankSetup(){
    leftFrontMotorForwardPin = TANK_MOTOR_1_FORWARD;
    leftFrontMotorReversePin = TANK_MOTOR_1_REVERSE;
    leftBackMotorForwardPin = TANK_MOTOR_2_FORWARD;
    leftBackMotorReversePin = TANK_MOTOR_2_REVERSE;

    rightFrontMotorForwardPin = TANK_MOTOR_3_FORWARD;
    rightFrontMotorReversePin = TANK_MOTOR_3_REVERSE;
    rightBackMotorForwardPin = TANK_MOTOR_4_FORWARD;
    rightBackMotorReversePin = TANK_MOTOR_4_REVERSE;

    isTank = true;

    tankForwardConstant = 9259;
    tankBackwardConstant = 9259;
    tankLeftConstant = 29;
    tankRightConstant = 29;

    pinMode(TANK_MOTOR_1_FORWARD, OUTPUT);
    pinMode(TANK_MOTOR_1_REVERSE, OUTPUT);
    pinMode(TANK_MOTOR_2_FORWARD, OUTPUT);
    pinMode(TANK_MOTOR_2_REVERSE, OUTPUT);
    pinMode(TANK_MOTOR_3_FORWARD, OUTPUT);
    pinMode(TANK_MOTOR_3_REVERSE, OUTPUT);
    pinMode(TANK_MOTOR_4_FORWARD, OUTPUT);
    pinMode(TANK_MOTOR_4_REVERSE, OUTPUT);
}

void Robot::turnOffMotors(){
    if(isTank){
        digitalWrite(leftFrontMotorForwardPin, 0);
        digitalWrite(leftFrontMotorReversePin, 0);

        digitalWrite(leftBackMotorForwardPin, 0);
        digitalWrite(leftBackMotorReversePin, 0);
        
        digitalWrite(rightFrontMotorForwardPin, 0);
        digitalWrite(rightFrontMotorReversePin, 0);

        digitalWrite(rightBackMotorForwardPin, 0);
        digitalWrite(rightBackMotorReversePin, 0);

    }
    else{
        digitalWrite(leftFrontMotorForwardPin, LOW);
        digitalWrite(leftFrontMotorReversePin, LOW);
        analogWrite(leftMotorAnalogPin, 0);
        digitalWrite(rightFrontMotorForwardPin, LOW);
        digitalWrite(rightFrontMotorReversePin, LOW);
        analogWrite(rightMotorAnalogPin, 0);

    }
}



void Robot::moveLinear(double distance, double power){
    if(isTank){
        if(power > 0){
            analogWrite(leftFrontMotorForwardPin, abs((int)(power * 255)));
            digitalWrite(leftFrontMotorReversePin, 0);
            analogWrite(leftBackMotorForwardPin, abs((int)(power * 255)));
            digitalWrite(leftBackMotorReversePin, 0);
            analogWrite(rightFrontMotorForwardPin, abs((int)(power * 255)));
            digitalWrite(rightFrontMotorReversePin, 0);
            analogWrite(rightBackMotorForwardPin, abs((int)(power * 255)));
            digitalWrite(rightBackMotorReversePin, 0);

            delay((int)(distance * tankForwardConstant));
        }
        else{
            analogWrite(leftFrontMotorReversePin, abs((int)(power * 255)));
            digitalWrite(leftFrontMotorForwardPin, 0);
            analogWrite(leftBackMotorReversePin, abs((int)(power * 255)));
            digitalWrite(leftBackMotorForwardPin, 0);
            analogWrite(rightFrontMotorReversePin, abs((int)(power * 255)));
            digitalWrite(rightFrontMotorForwardPin, 0);
            analogWrite(rightBackMotorReversePin, abs((int)(power * 255)));
            digitalWrite(rightBackMotorForwardPin, 0);

            delay((int)(distance * tankBackwardConstant));
        }
    }
    else{
        if(power > 0){
            digitalWrite(leftFrontMotorForwardPin, HIGH);
            digitalWrite(leftFrontMotorReversePin, LOW);
            analogWrite(leftMotorAnalogPin, abs((int)(power * 255)));

            digitalWrite(rightFrontMotorForwardPin, HIGH);
            digitalWrite(rightFrontMotorReversePin, LOW);
            analogWrite(rightMotorAnalogPin, abs((int)(power * 255)));

            delay((int)(distance * robotForwardConstant));
        }
        else{
            digitalWrite(leftFrontMotorForwardPin, LOW);
            digitalWrite(leftFrontMotorReversePin, HIGH);
            analogWrite(leftMotorAnalogPin, abs((int)(power * 255)));

            digitalWrite(rightFrontMotorForwardPin, LOW);
            digitalWrite(rightFrontMotorReversePin, HIGH);
            analogWrite(rightMotorAnalogPin, abs((int)(power * 255)));

            delay((int)(distance * robotBackwardConstant));
        }
    }
    Robot::turnOffMotors();
}

void Robot::spin(double degrees, double power){
    if(isTank){
        if(degrees > 0){
            analogWrite(leftFrontMotorForwardPin, abs((int)(power * 255)));
            digitalWrite(leftFrontMotorReversePin, 0);

            analogWrite(leftBackMotorForwardPin, abs((int)(power * 255)));
            digitalWrite(leftBackMotorReversePin, 0);

            analogWrite(rightFrontMotorReversePin, abs((int)(power * 255)));
            digitalWrite(rightFrontMotorForwardPin, 0);

            analogWrite(rightBackMotorReversePin, abs((int)(power * 255)));
            digitalWrite(rightBackMotorForwardPin, 0);

            delay(abs((int)(degrees * tankRightConstant)));
            Robot::turnOffMotors();
        }
        else{
            analogWrite(leftFrontMotorReversePin, abs((int)(power * 255)));
            digitalWrite(leftFrontMotorForwardPin, 0);

            analogWrite(leftBackMotorReversePin, abs((int)(power * 255)));
            digitalWrite(leftBackMotorForwardPin, 0);

            analogWrite(rightFrontMotorForwardPin, abs((int)(power * 255)));
            digitalWrite(rightFrontMotorReversePin, 0);

            analogWrite(rightBackMotorForwardPin, abs((int)(power * 255)));
            digitalWrite(rightBackMotorReversePin, 0);

            delay(abs((int)(degrees * tankLeftConstant)));
            Robot::turnOffMotors();
        }
    }
    else{
        if(degrees > 0){
            digitalWrite(leftFrontMotorForwardPin, HIGH);
            digitalWrite(leftFrontMotorReversePin, LOW);
            analogWrite(leftMotorAnalogPin, abs((int)(power * 255)));

            digitalWrite(rightFrontMotorForwardPin, LOW);
            digitalWrite(rightFrontMotorReversePin, HIGH);
            analogWrite(rightMotorAnalogPin, abs((int)(power * 255)));

            delay(abs((int)(degrees * robotRightConstant)));
            Robot::turnOffMotors();
        }
        else{
            digitalWrite(leftFrontMotorForwardPin, LOW);
            digitalWrite(leftFrontMotorReversePin, HIGH);
            analogWrite(leftMotorAnalogPin, abs((int)(power * 255)));

            digitalWrite(rightFrontMotorForwardPin, HIGH);
            digitalWrite(rightFrontMotorReversePin, LOW);
            analogWrite(rightMotorAnalogPin, abs((int)(power * 255)));

            delay(abs((int)(degrees * robotLeftConstant)));
            Robot::turnOffMotors();
        }
    }
    Robot::turnOffMotors();
}
