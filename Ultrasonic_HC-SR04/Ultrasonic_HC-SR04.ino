// Use the PINS you connect the sensor to
#define TRIGGER_PIN 11
#define ECHO_PIN 10

long duration;
int distance_cm;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  //clear the trigger pin
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(5);
  //issue the trigger
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  //stop the trigger
  digitalWrite(TRIGGER_PIN, LOW);

  //measure the signal duration
  duration = pulseIn(ECHO_PIN, HIGH);

  Serial.print("Duration:");
  Serial.println(duration);

  distance_cm = calculateDistanceInCm(duration);

  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println("cm");

  delay(500);
}

/**
 * Calculates the distance in cm for a given echo duration in micro-senconds
 * 
 * The distance = time * speed
 * The time is duration/2 (as the signal travels there and back.)
 * The speed of sound at 20°C is roughly 0.0343 cm/micro-second
 * The distance will be returned in whole integers only.
 * 
 * @param duration: the duration the signal travels in micro-seconds
 */
int calculateDistanceInCm(long duration){
  return (duration / 2) * 0.0343;
}
