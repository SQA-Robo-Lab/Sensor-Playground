#define IR_SIGNAL_PIN 40 //define your pin connected to OUT

void setup() {
  Serial.begin(9600);
  pinMode(IR_SIGNAL_PIN, INPUT);
}

void loop() {
  int sensorSignal = digitalRead(IR_SIGNAL_PIN);
  if (lineDetected(sensorSignal)){
    Serial.println("Line deteced!");
  } else {
    Serial.println("No line detected");
  }
  delay(1000);
}

/**
 * Returns true iff the sensor signals that it detected a dark line.
 * 
 * @param signal: integer handing over the digitalRead of the sensor pin.
 */
boolean lineDetected(int signal){
  return signal == 1;
}
