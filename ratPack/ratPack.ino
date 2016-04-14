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
int leftSpeed = 0;
int rightSpeed = 0;
int totalError = 0;
int oldError = 0;
int errorD = 0;

void calculations() {
  readSensors();
  //isRightWall = rightSensor > 350;
  isRightWall = rightMiddle > 650;
  isLeftWall = leftMiddle > 650;
  //isLeftWall = leftSensor > 350;
  int error = (leftMiddle - rightMiddle)/10 + 90;
  int sideError = (leftSensor - rightSensor)/100;
  Serial.println(rightMiddle);
  Serial.println(leftMiddle);
  Serial.println();
  if (!isRightWall && leftMiddle > 1200) {
    isRightWall = true;
    totalError = 100;
  }
  if (isLeftWall && isRightWall)
    totalError = error;
  else {
    totalError = 0;
  }
  oldError = error;
}

void moveForward() {
  leftSpeed = 150 + totalError;
  rightSpeed = 150 - totalError;
  setSpeed(leftSpeed, rightSpeed);
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

void slowDown() {

  int i = 1000000;
  while(leftSpeed > 0 || rightSpeed > 0){
    if (leftSpeed <= 0 || rightSpeed <= 0){
      setSpeed(0,0);
      break;
    }
    if(i-- % 7 == 0 || i == 0){
      leftSpeed -= 1;
      rightSpeed -= 1;
    }
    setSpeed(leftSpeed, rightSpeed);
  }
  analogWrite(MR1, 2047);
  analogWrite(MR2, 2047);
  analogWrite(ML1, 2047);
  analogWrite(ML2, 2047);
}
void loop() {
  //while(leftFront < 1100 && rightFront < 1100) {
  //   moveForward();
  //}
  //setSpeed(-150,-150);
  
  while (isRightWall){ 
    moveForward();
  }
  //digitalWrite(LED, LOW);  
  slowDown();
  //setSpeed(0, 0);
  //delay(1000);
  while(1);
  //setSpeed(0,0);
  //turnRight();

}
