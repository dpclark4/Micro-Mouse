#include "Arduino.h"
#include "Motors.h"
#include "Sensors.h"
const int LED = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  setupSensors();
  setupMotors();
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  setLeftPWM(-200);
  setRightPWM(-200);
//Serial.println(rightTicks);
  delay(50);
}
