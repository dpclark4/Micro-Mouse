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
bool isLeftWall;
bool isRightWall;
bool isFrontWall;
int leftSpeed = 0;
int rightSpeed = 0;
int totalError = 0;
int oldError = 0;
int errorD = 0;
int rightError = 0;
int leftError = 0;

void calculations() {
  readSensors();
  isRightWall = rightMiddle > 650;
  isLeftWall = leftMiddle > 650;
  //isRightWall = rightSensor > 350;
  //isLeftWall = leftSensor > 350;
  isFrontWall = (rightFront + leftFront)/2 > 980;

  if(isFrontWall) {
    isRightWall = rightSensor > 350;
    isLeftWall = leftSensor > 350;
  }
  
  int error = (leftMiddle - rightMiddle)/10 + 27;
  int sideError = (leftSensor - rightSensor)/100;
  
   // use this and next loop if rightWall is detected with middle
  if (rightMiddle < 650 && leftMiddle > 1200) {
    totalError = 150;
  } else if (leftMiddle < 650 && rightMiddle > 2200) {
    totalError = -150;
  } else if (isLeftWall && isRightWall){
    totalError = error;
  } else {
    totalError = 0;
    //setSpeed(0, 0);
    //delay(10000);
  }
  oldError = error;
}

void moveForward() {
  leftSpeed = 250 + totalError;
  rightSpeed = 250 - totalError;
  setSpeed(leftSpeed, rightSpeed);
}

void setSpeed(int l, int r){
  leftSpeed = l;
  rightSpeed = r;
  setLeftPWM(l);
  setRightPWM(r);
}

void slowDown() {
  if (leftSpeed == 0 || rightSpeed == 0){
    return;
  }
  rightTicks = 0;
  leftTicks = 0;
  while(rightTicks < 150 && leftTicks < 150);
  for(int i = leftSpeed*2; i >= 0; i--){
    if(leftSpeed > 0 && rightSpeed > 0){
      if(i % 2 == 0){
        setSpeed(i/2, i/2);
      }
    }
    setSpeed(0, 0);
  }
}

void loop() {
  while(!isFrontWall && isRightWall) {
    moveForward();
  }
  slowDown();
  delay(1000);
  if(!isLeftWall && leftSensor < 350){
    turnLeftInPlace();
  }
  else if(!isRightWall){
    turnRightInPlace();
  } else{
    turnAroundInPlace();
    delay(1000);
  }
}

