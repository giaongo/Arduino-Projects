const int switchPin = 8; 
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2; 
long interval = 30000;

void setup() {
  Serial.begin(9600);
    for(int x = 2; x < 8; x++) {
      pinMode(x, OUTPUT);
    }
    pinMode(switchPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
  if(currentTime - previousTime > interval) {
    Serial.println("30 seconds has passed");
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;
    if(led == 7) {
      led = 2;
    }
  }
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState) {
    Serial.println("State has changed");
    for(int x = 2; x < 8; x++) {
      digitalWrite(x, LOW);
    }
    led = 2;
    previousTime = currentTime;
  }
  prevSwitchState = switchState;
}
