#include "Arduino.h"
#include "Motors.h"
#include "Sensors.h"
const int LED = 13;
int oldErrorP = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  delay(2000);
  setupSensors();
  setupMotors();
  delay(100);
}

void loop() {
  readSensors();
  int errorP = rightSensor - leftSensor;
  int totalError = 10 * errorP;
  setLeftPWM(150 - totalError / 124);
  setRightPWM(150 + totalError / 124);
  delay(1);

}
