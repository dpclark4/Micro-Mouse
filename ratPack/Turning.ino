void turnRight(){
  int startAngle = angle;
  //do until gyroscope reads 90
  do
  {  //make left wheels turn
      setLeftPWM(350);
      //right wheels backward
      setRightPWM(-350);
  }while (angle < (90+startAngle));
  setLeftPWM(0);
  setRightPWM(0);
  digitalWrite(LED, LOW);
}

void turnLeft(){
  int startAngle = angle;
  //do until gyroscope reads 90
  do
  {   //make right wheels turn
      setRightPWM(200); 
      //left wheels backward
      setLeftPWM(-200);
  }while (angle > (startAngle-90));
  setLeftPWM(0);
  setRightPWM(0);
}
