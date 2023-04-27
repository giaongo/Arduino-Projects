const int piezoPin = 12;
const int buttonPin = 9;
const int ledBluePin = 3;
const int ledYellowPin = 2;


int led = 2;
int prevButtonState = 0;
int currentButtonState = 0;
unsigned long previousTime = 0;
long interval = 10000;
int index = 0;

void setup() {
  Serial.begin(9600);
  for(int led = 2; led < 4; led++) {
    pinMode(led, OUTPUT);
  }
  pinMode(piezoPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  currentButtonState = digitalRead(buttonPin);
  if(currentTime - previousTime > interval) {
    if(led < 4) {
      digitalWrite(led, HIGH);
      led += 1;
    }
    tone(piezoPin, 200);
  }
  if(currentButtonState != prevButtonState) {
    Serial.println("Button is pressed");
    noTone(piezoPin);
    for(int led = 2; led < 4; led++) {
      digitalWrite(led,LOW);
    }
    led = 2;
    previousTime = currentTime;
  }
  prevButtonState = currentButtonState;
}
