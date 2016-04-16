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
int count = 0;
int prevTicks = 0;
bool hasMoved = false;

void calculations() {
  readSensors();
  count++;
  isRightWall = rightMiddle > 650;
  isLeftWall = leftMiddle > 650;
  //isRightWall = rightSensor > 350;
  //isLeftWall = leftSensor > 350;
  isFrontWall = (rightFront + leftFront)/2 > 900;

  if(isFrontWall) {
    isRightWall = rightSensor > 350;
    isLeftWall = leftSensor > 350;
  }
  
  int error = (leftMiddle - rightMiddle)/10 + 90;
  int sideError = (leftSensor - rightSensor)/100;
  //Serial.println(rightMiddle);
  //Serial.println(leftMiddle);
  //Serial.println()
  Serial.print(leftTicks);
  Serial.print(" ");
  Serial.print(rightTicks);
  Serial.print("\n");
  /*
  Serial.print(leftError);
  Serial.print(" ");
  Serial.print(leftSensor);
  Serial.print("    ");
  Serial.print(rightError);
  Serial.print(" ");
  Serial.print(rightSensor);
  Serial.print("    ");
  Serial.print(error);
  Serial.print("\n");
  */
  if (count >= 2000 && rightTicks == prevTicks && hasMoved) {
    setSpeed(0,0);
    rightTicks = 0;
    while (rightTicks > -15 || rightTicks < 15) {
      setSpeed(-250, -250) ;
    }
    setSpeed(0,0);
    count = 0;
  }
   
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
  prevTicks = rightTicks;
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

  while(!isFrontWall) {
    moveForward();
    hasMoved = true;
  }
  slowDown();
  delay(1000);
  if (!isRightWall) {
    
    turnRightInPlace();
    
    forwardOneCell();
  }
  else if (!isLeftWall) {
    
    turnLeftInPlace();
    
    forwardOneCell();
  }
  else if (isLeftWall && isRightWall && isFrontWall) {
    turnAround();  
  }

  
  /*
  moveForward();
  if(isFrontWall) && !isRightWall){
    slowDown();
    delay(1000);
    turnRightInPlace();
  } else if(isFrontWall){
    slowDown();
    delay(1000);
    turnRightInPlace();
    delay(1000);
    turnRightInPlace();
  }else if(!isRightWall){
    slowDown();
    delay(1000);
    turnRightInPlace();
    delay(500);
    forwardOneCell();
  }
  */
}
