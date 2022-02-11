#include "MotorDriver.c"

void setup(){
    Serial.begin(9600);
    initMotorDriver();
    Serial.println("Setup done!");
}

void loop(){
    driveForward(50);
    delay(2000);
    driveReverse(50);
    delay(2000);
    turnRightForward(80);
    delay(2000);
    turnLeftForward(80);
    delay(2000);
    stop();
    delay(2000);
    steerLeftForward(80, 5.0);
    delay(2000);
    steerRightForward(80, 5.0);
    delay(1000);
    driveReverse(50);
    delay(2000);
    stop();
    delay(10000);
}