#include "arduino_secrets.h"

#include "FTDebouncer.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/b87d3b2d-714b-4eb0-a941-b60959a41170 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  bool button_toggle;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/
#include "thingProperties.h"
#define buttonPin 5
#define piezoPin 1
#define ledPin 4
FTDebouncer buttons;
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  pinMode(buttonPin, INPUT);
  pinMode(piezoPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  buttons.addPin(buttonPin,LOW);
  buttons.init();
}

void loop() {
  ArduinoCloud.update();
  buttons.update();
 
}

void onPinActivated(int pinNumber) {
  Serial.println("Pin activated");
  button_toggle = !button_toggle;
  onButtonToggleChange();
}

void onPinDeactivated(int pinNumber) {
  Serial.println("Pin deactivated");
  Serial.println(pinNumber);
  onButtonToggleChange();
}

/*
  Since ButtonToggle is READ_WRITE variable, onButtonToggleChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onButtonToggleChange()  {
  // Add your code here to act upon ButtonToggle change
  if(button_toggle) {
    tone(piezoPin, 300);
    digitalWrite(ledPin, HIGH);
    Serial.println("ON");
  } else {
    noTone(piezoPin);
    digitalWrite(ledPin,LOW);
    Serial.println("OFF");
  }
}