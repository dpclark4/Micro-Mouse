#include "Arduino.h"
#include "Motors.h"
#include "Sensors.h"
const int buttonPin = 24;
const int LED = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  setupSensors();
  setupMotors();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  setLeftPWM(200);
  setRightPWM(200);
}
