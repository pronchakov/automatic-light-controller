int sensorPin = A0;
int relayPin = 13;

int sensorValue = 0;
int second = 1000;
int delayValue = second * 10;
int loopsBeforeInitialState = 6 * 3;
int loopsCurrent = 0;

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  if (sensorValue > 500) {
    digitalWrite(relayPin, LOW);
    loopsCurrent = 0;
  } else {
    if (loopsCurrent > loopsBeforeInitialState) {
      digitalWrite(relayPin, HIGH);
      loopsCurrent = 0;
    }
  }
  Serial.print("loopsCurrent: ");
  Serial.print(loopsCurrent);

  Serial.print(", sensorValue: ");
  Serial.println(sensorValue);
  delay(delayValue);
}
