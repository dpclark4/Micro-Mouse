#include "Arduino.h"
#include "Motors.h"
#include "Sensors.h"

const int LED = 13;
IntervalTimer timer;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  setupSensors();
  setupMotors();
  readSensors();
  timer.begin(calculations, 1000);
  Serial.begin(115200);
  delay(2000);
  //turnRight();
}
int totalError = 0;
int oldError = 0;
int errorD = 0;
void calculations() {
  readSensors();
  int error = (leftMiddle - rightMiddle)/10 + 80;
  //errorD = error - oldError; 
  //totalError = ((error * 3 + .5 * errorD)*3)/150;
  int sideError = (leftSensor - rightSensor)/100;
  Serial.println(sideError);
  setSpeed(150 + error, 150 - error);
  oldError = error;
}

void setSpeed(int l, int r){
  setLeftPWM(l);
  setRightPWM(r);
}
void makeLeftTurn() {
    rightTicks = 0;
    leftTicks = 0;
    while(leftTicks < 150 && rightTicks < 330) {
      setSpeed(150, 150);
    }
    while(rightTicks < 330) {
      setSpeed(0, 150);
    }
}
void loop() {
  while(leftFront < 900 && rightFront < 900) {
     //moveForward();
  }
  setSpeed(0,0);

  rightTicks = 0;
  leftTicks = 0;
  while (leftTicks > -150 && rightTicks > -150) {
    setLeftPWM(-140);
    setRightPWM(-140);
  }
  rightTicks = 0;
  leftTicks = 0;
  makeLeftTurn();
  setSpeed(0,0);

  /*
  while (rightTicks < 250) {
    setRightPWM(130);
  }
  setRightPWM(0);
 */
}
