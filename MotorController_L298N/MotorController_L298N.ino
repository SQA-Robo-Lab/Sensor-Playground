#define LEFT_ENGINE_SPEED_PIN 7
#define RIGHT_ENGINE_SPEED_PIN 2

#define LEFT_ENGINE_FORWARD_PIN 5
#define LEFT_ENGINE_REVERSE_PIN 6
#define RIGHT_ENGINE_FORWARD_PIN 4
#define RIGHT_ENGINE_REVERSE_PIN 3

void setup(){
    Serial.begin(9600);
    pinMode(LEFT_ENGINE_SPEED_PIN, OUTPUT);
    pinMode(RIGHT_ENGINE_SPEED_PIN, OUTPUT);
    pinMode(LEFT_ENGINE_FORWARD_PIN, OUTPUT);
    pinMode(LEFT_ENGINE_REVERSE_PIN, OUTPUT);
    pinMode(RIGHT_ENGINE_FORWARD_PIN, OUTPUT);
    pinMode(RIGHT_ENGINE_REVERSE_PIN, OUTPUT);

    Serial.println("Setup done!");
}

void loop(){
    forward(80);
    delay(2000);
    forward(50);
    delay(2000);
    forward(100);
    delay(2000);
    reverse(100);
    delay(2000);
    turnRight(150);
    delay(2000);
    turnLeft(150);
    delay(2000);
    stop();
    delay(2000);
    steerLeftForward(150, 2);
    delay(2000);
    steerRightForward(150, 2);
    delay(1000);
    reverse(100);
    delay(2000);
    stop();
    delay(10000);
}

void rightForward(){
    digitalWrite(RIGHT_ENGINE_FORWARD_PIN, HIGH);
    digitalWrite(RIGHT_ENGINE_REVERSE_PIN, LOW);
}

void rightReverse(){
    digitalWrite(RIGHT_ENGINE_FORWARD_PIN, LOW);
    digitalWrite(RIGHT_ENGINE_REVERSE_PIN, HIGH);
}

void leftForward(){
    digitalWrite(LEFT_ENGINE_FORWARD_PIN, HIGH);
    digitalWrite(LEFT_ENGINE_REVERSE_PIN, LOW);
}

void leftReverse(){
    digitalWrite(LEFT_ENGINE_FORWARD_PIN, LOW);
    digitalWrite(LEFT_ENGINE_REVERSE_PIN, HIGH);
}

void rightSpeed(int speed){
    analogWrite(RIGHT_ENGINE_SPEED_PIN, speed);
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

void forward(int speed){
    setSpeed(speed);
    forward();
}

void reverse(){
    leftReverse();
    rightReverse();
}

void reverse(int speed){
    setSpeed(speed);
    reverse();
}

void turnLeft(){
    rightForward();
    leftReverse();
}

void turnLeft(int speed){
    setSpeed(speed);
    turnLeft();
}

void turnRight(){
    leftForward();
    rightReverse();
}

void turnRight(int speed){
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