#include <Servo.h>
Servo myServo;
int const potPin = A0;
int potValue;
int angle;


void setup() {
  // tell what pin the servo is attached to
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);
  Serial.print("PotValue is: ");
  Serial.print(potValue);
  delay(15);
  angle = map(potValue, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
}
