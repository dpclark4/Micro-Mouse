#include "Arduino.h"
#include "Motors.h"
#include "Sensors.h"
const int buttonPin = 24;
const int LED = 11;
IntervalTimer getValues;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  setupSensors();
  setupMotors();
  getValues.begin(readSensors, 100000);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  //setLeftPWM(200);
  //setRightPWM(200);
  while(leftFront < 2500 && rightFront < 2500) {
    setLeftPWM(200);
    setRightPWM(200);
  }
  setLeftPWM(0);
  setRightPWM(0);
  rightTicks = 0;
  leftTicks = 0;
  while (leftTicks > -500 && rightTicks > -500) {
    setLeftPWM(-100);
    setRightPWM(-100);
  }
  
}
