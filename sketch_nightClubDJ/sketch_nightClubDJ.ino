const int potentiometerPin = A0;
const int piezoPin = 8;
const int groupLedYellowBluePin = 6;
const int groupLedGreenRedPin = 5;
int potentioValue = 0;
int piezoValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(groupLedYellowBluePin, OUTPUT);
  pinMode(groupLedGreenRedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potentioValue = analogRead(potentiometerPin);

  piezoValue = map(potentioValue, 0, 1023, 30, 300);
  Serial.print("potentiometer: ");
  Serial.print(potentioValue);
  Serial.print("\t piezo value: ");
  Serial.println(piezoValue);

  if (piezoValue < 100) {
    analogWrite(groupLedYellowBluePin, potentioValue);
    analogWrite(groupLedGreenRedPin, 0);
  } else {
    analogWrite(groupLedGreenRedPin, potentioValue);
    analogWrite(groupLedYellowBluePin, 0);
  }
  tone(8, piezoValue, 20);

  delay(15);
}
