#define sensorPin 9
#define ledPin 6

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long duration;
  float distance;

  // Send trigger
  pinMode(sensorPin, OUTPUT);
  digitalWrite(sensorPin, LOW); delayMicroseconds(2);
  digitalWrite(sensorPin, HIGH); delayMicroseconds(10);
  digitalWrite(sensorPin, LOW);

  // Read echo
  pinMode(sensorPin, INPUT);
  duration = pulseIn(sensorPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 10) {
    digitalWrite(ledPin, HIGH);  // Alert LED ON
  } else {
    digitalWrite(ledPin, LOW);   // Alert LED OFF
  }

  delay(1000);
}
