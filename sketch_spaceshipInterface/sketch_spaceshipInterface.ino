int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);
  if (switchState == LOW) {

    Serial.println("Button is not pressed");
    digitalWrite(3, HIGH); //green led
    digitalWrite(4, LOW); // red led
    digitalWrite(5, LOW); // red led
  } else {
    Serial.println("Button is pressed");
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);

    delay(250);
    digitalWrite(4,HIGH);
    delay(250);
    digitalWrite(3,HIGH);
  }
  delay(250);
}
