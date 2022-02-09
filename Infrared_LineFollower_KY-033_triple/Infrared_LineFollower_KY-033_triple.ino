//define your pins connected to OUT/SIGNAL
#define IR_SIGNAL_PIN_LEFT 30
#define IR_SIGNAL_PIN_CENTER 32
#define IR_SIGNAL_PIN_RIGHT 34

void setup() {
  Serial.begin(9600);
  pinMode(IR_SIGNAL_PIN_LEFT, INPUT);
  pinMode(IR_SIGNAL_PIN_CENTER, INPUT);
  pinMode(IR_SIGNAL_PIN_RIGHT, INPUT);
}

void loop() {
  int sensorSignalLeft = digitalRead(IR_SIGNAL_PIN_LEFT);
  int sensorSignalCenter = digitalRead(IR_SIGNAL_PIN_CENTER);
  int sensorSignalRight = digitalRead(IR_SIGNAL_PIN_RIGHT);

  Serial.print("L: ");
  Serial.print(sensorSignalLeft);
  Serial.print(" | C: ");
  Serial.print(sensorSignalCenter);
  Serial.print(" | R: ");
  Serial.println(sensorSignalRight);


  if (onLine(sensorSignalLeft, sensorSignalCenter, sensorSignalRight)){
    Serial.println("The car is ON the line - drive straight ahead!");
  } else if (leftOfLine(sensorSignalLeft, sensorSignalCenter, sensorSignalRight)){
    Serial.println("The car is LEFT of the line - steer RIGHT! ->");
  } else if (rightOfLine(sensorSignalLeft, sensorSignalCenter, sensorSignalRight)){
    Serial.println("The car is RIGHT of the line - steer LEFT! <-");
  }
  

  delay(500);
}

boolean onLine(int left, int center, int right){
  return ( (left == 0) && (center == 1) && (right == 0) );
}


boolean leftOfLine(int left, int center, int right){
  //return ( (left == 0) && (center == 0) && (right == 1) );
  return ( (left == 0) && (right == 1) );
}


boolean rightOfLine(int left, int center, int right){
  //return ( (left == 1) && (center == 0) && (right == 0) );
  return ( (left == 1) && (right == 0) );
}
