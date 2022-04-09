int firstMin = 10;
int secondMin = 15;
int thirdMin = 25;

int FIRST = 3;
int SECOND = 4;
int THIRD = 5;

int previousValue = 0;

void setup() {
  pinMode(FIRST, OUTPUT);
  pinMode(SECOND, OUTPUT);
  pinMode(THIRD, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(FIRST, LOW);
  digitalWrite(SECOND, LOW);
  digitalWrite(THIRD, LOW);
  
  int sensorValue = analogRead(A0);
  int change = abs(previousValue - sensorValue);
  
  //Serial.println(change);
  previousValue = sensorValue;

  if (change > thirdMin) {
    digitalWrite(THIRD, HIGH);
  } else if (change > secondMin) {
    digitalWrite(SECOND, HIGH);
  } else if (change > firstMin) {
    digitalWrite(FIRST, HIGH);
  }
  delay(10);        // delay in between reads for stability
}
