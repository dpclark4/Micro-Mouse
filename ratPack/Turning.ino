#include "Motors.h"
#include "Sensors.h"
#include "Gyro.h"

void loop() {
  //read sensor values until there are no walls on one or more sides
  readSensors();
  if(leftSensor < 300){
    turnLeft();
  } else if (rightSensor < 300){
    turnRight();
  }
}

void turnRight(){
  int startAngle = angle;
  //do until gyroscope reads 90
  do
  {  //make left wheels turn
      setLeftPWM(150);
      //right wheels backward
      setRightPWM(-150)
  }while (angle < (90+startAngle));
  setLeftPWM(0);
  setRightPWM(0);
}

void turnLeft(){
  int startAngle = angle;
  //do until gyroscope reads 90
  do
  {   //make right wheels turn
      setRightPWM(150) 
      //left wheels backward
      setLeftPWM(-150)
  }while (angle > (startAngle-90));
  setLeftPWM(0);
  setRightPWM(0);
}
