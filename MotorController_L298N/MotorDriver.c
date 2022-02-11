#include "Arduino.h"

#define LEFT_ENGINE_SPEED_PIN 7
#define RIGHT_ENGINE_SPEED_PIN 2

#define LEFT_ENGINE_FORWARD_PIN 5
#define LEFT_ENGINE_REVERSE_PIN 6
#define RIGHT_ENGINE_FORWARD_PIN 4
#define RIGHT_ENGINE_REVERSE_PIN 3

void initMotorDriver(){
    pinMode(LEFT_ENGINE_SPEED_PIN, OUTPUT);
    pinMode(RIGHT_ENGINE_SPEED_PIN, OUTPUT);
    pinMode(LEFT_ENGINE_FORWARD_PIN, OUTPUT);
    pinMode(LEFT_ENGINE_REVERSE_PIN, OUTPUT);
    pinMode(RIGHT_ENGINE_FORWARD_PIN, OUTPUT);
    pinMode(RIGHT_ENGINE_REVERSE_PIN, OUTPUT);
}

void rightForward(){
    digitalWrite(RIGHT_ENGINE_FORWARD_PIN, HIGH);
    digitalWrite(RIGHT_ENGINE_REVERSE_PIN, LOW);
}

void rightReverse(){
    digitalWrite(RIGHT_ENGINE_FORWARD_PIN, LOW);
    digitalWrite(RIGHT_ENGINE_REVERSE_PIN, HIGH);
}

void rightSpeed(int speed){
    analogWrite(RIGHT_ENGINE_SPEED_PIN, speed);
}

void leftForward(){
    digitalWrite(LEFT_ENGINE_FORWARD_PIN, HIGH);
    digitalWrite(LEFT_ENGINE_REVERSE_PIN, LOW);
}

void leftReverse(){
    digitalWrite(LEFT_ENGINE_FORWARD_PIN, LOW);
    digitalWrite(LEFT_ENGINE_REVERSE_PIN, HIGH);
}

void leftSpeed(int speed){
    analogWrite(LEFT_ENGINE_SPEED_PIN, speed);
}

void setSpeed(int speed){
    leftSpeed(speed);
    rightSpeed(speed);
}

void stop(){
    setSpeed(0);
}

void forward(){
    leftForward();
    rightForward();
}

void driveForward(int speed){
    setSpeed(speed);
    forward();
}

void reverse(){
    leftReverse();
    rightReverse();
}

void driveReverse(int speed){
    setSpeed(speed);
    reverse();
}

void turnLeft(){
    rightForward();
    leftReverse();
}

void turnLeftForward(int speed){
    setSpeed(speed);
    turnLeft();
}

void turnRight(){
    leftForward();
    rightReverse();
}

void turnRightForward(int speed){
    setSpeed(speed);
    turnRight();
}

void steerLeftForward(int speed, double fraction){
    forward();
    leftSpeed(speed/fraction);
    rightSpeed(speed);
}

void steerRightForward(int speed, double fraction){
    forward();
    leftSpeed(speed);
    rightSpeed(speed/fraction);
}