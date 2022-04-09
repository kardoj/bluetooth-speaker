float multiplier = 0.1;
float firstMin = 10;
float secondMin = 20;
float thirdMin = 30;

int GREEN = 3;
int RED = 4;
int BLUE = 5;

int previousSensorValue = 0;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // Serial.begin(9600);
}

void loop() {
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, LOW);

  int sensorValue = analogRead(A0);
  int change = abs(previousSensorValue - sensorValue);
  // Serial.println(change);
  previousSensorValue = sensorValue;

  multiplier = max(min(change, 30) / 30, 0.1);
  
  if (change >= thirdMin * multiplier) {
    digitalWrite(RED, HIGH);
  } else if (change >= secondMin * multiplier) {
    digitalWrite(BLUE, HIGH);
  } else if (change >= firstMin * multiplier) {
    digitalWrite(GREEN, HIGH);
  }
  
  delay(10);
}
