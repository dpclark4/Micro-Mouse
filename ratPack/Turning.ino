void turnRightInPlace(){
  leftTicks = 0;
  rightTicks = 0;
  int LPWM = 200;
  int RPWM = -200;
  while (leftTicks < 80){
    setRightPWM(RPWM);
    setLeftPWM(LPWM);
  }
  setLeftPWM(0);
  setRightPWM(0);
  //digitalWrite(LED, LOW);
}

void turnLeftInPlace(){
  leftTicks = 0;
  rightTicks = 0;
  int RPWM = 200;
  int LPWM = -200;
  while (rightTicks < 80){
    setRightPWM(RPWM);
    setLeftPWM(LPWM);
  }
  setLeftPWM(0);
  setRightPWM(0);
  //digitalWrite(LED, LOW);
}

void turnAroundInPlace(){
  leftTicks = 0;
  rightTicks = 0;
  int RPWM = 200;
  int LPWM = -200;
  while (rightTicks < 200){
    setRightPWM(RPWM);
    setLeftPWM(LPWM);
  }
  setLeftPWM(0);
  setRightPWM(0);
  //digitalWrite(LED, LOW);
}

void forwardOneCell(){
  leftTicks = 0;
  rightTicks = 0;
  int RPWM = 200;
  int LPWM = 200;
  while (leftTicks < 200){
    setRightPWM(RPWM);
    setLeftPWM(LPWM);
  }
  //slowDown();
  setSpeed(0,0);
}

