const float tempBase = 24.0;
const int sensorPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber < 6; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  float voltageFromSensor = (sensorVal/1024.0) * 5.0;
  float temperature = (voltageFromSensor - 0.5) * 100;
  Serial.print("Temperature value is: ");
  Serial.print(temperature);
  Serial.println();

  if(temperature > tempBase && temperature <= tempBase + 1) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH); 
  } else {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
  delay(250);
}
