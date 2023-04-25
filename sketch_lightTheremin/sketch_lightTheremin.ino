int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0; 
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);  
  Serial.begin(9600);

  while (millis() < 5000) {
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    } 
    if(sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }

  }
  Serial.print("Sensor Low: ");
  Serial.print(sensorLow);
  Serial.print("Sensor High: ");
  Serial.print(sensorHigh);
  digitalWrite(ledPin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 30, 600);
  Serial.print("Sensor value : ");
  Serial.print(sensorValue);
  Serial.print("\tPitch value: ");
  Serial.println(pitch);
  tone(8, pitch, 20);
  delay(20);
}
