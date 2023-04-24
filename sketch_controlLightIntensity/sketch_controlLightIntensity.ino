int const potPin = A0; 
int const redLedPin = 11;
int const blueLedPin = 10;
int const greenLedPin = 9;
int redValue = 0;
int blueValue = 0;
int greenValue = 0;
int potValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);
  Serial.print("Pot value is: ");
  Serial.print(potValue);

  delay(20);

  redValue = potValue / 4;
  blueValue = potValue / 4;
  greenValue = potValue / 4;
  Serial.print("Mapped sensor value: ");
  Serial.print(redValue);
  Serial.print("\t blue: ");
  Serial.print(blueValue);
  Serial.print("\t green: ");
  Serial.println(greenValue);

  analogWrite(redLedPin, redValue);
  analogWrite(blueLedPin, blueValue);
  analogWrite(greenLedPin, greenValue);

}
