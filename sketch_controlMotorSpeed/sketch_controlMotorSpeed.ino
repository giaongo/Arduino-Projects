const int potentiometerPin = A0;
const int motorPin = 9;
int switchState = 0;
int potValue = 0;
void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potentiometerPin);
  analogWrite(motorPin, potValue);
}
