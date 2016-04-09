void turnRight(){
  int startAngle = angle;
  //do until gyroscope reads 90
  do
  {  //make left wheels turn
      setLeftPWM(350);
      //right wheels backward
<<<<<<< HEAD
      setRightPWM(-350);
=======
      setRightPWM(-150);
>>>>>>> origin/master
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
<<<<<<< HEAD
      setRightPWM(200); 
      //left wheels backward
      setLeftPWM(-200);
=======
      setRightPWM(150) ;
      //left wheels backward
      setLeftPWM(-150);
>>>>>>> origin/master
  }while (angle > (startAngle-90));
  setLeftPWM(0);
  setRightPWM(0);
}
