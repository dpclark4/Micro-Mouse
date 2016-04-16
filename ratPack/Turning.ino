void turnRight(){
  leftTicks = 0;
  rightTicks = 0;
  int LPWM = 300;
  int RPWM = -100;
  while (leftTicks < 145){
    setRightPWM(RPWM);
    setLeftPWM(LPWM);
  }
  while (RPWM < 0){
    LPWM = LPWM - 80;
    RPWM = RPWM + 50;
    setRightPWM(RPWM);
    setLeftPWM(LPWM);
  }
  setLeftPWM(0);
  setRightPWM(0);
  digitalWrite(LED, LOW);
}

void turnRightInPlace(){
  leftTicks = 0;
  rightTicks = 0;
  int LPWM = 599;
  int RPWM = -200;
  while (leftTicks < 83){
    setRightPWM(RPWM);
    setLeftPWM(LPWM);
  }
  setLeftPWM(0);
  setRightPWM(0);
  //digitalWrite(LED, LOW);
}

void turnLeft(){
  leftTicks = 0;
  rightTicks = 0;
  int RPWM = 300;
  int LPWM = -100;
  while (rightTicks < 145){
    setRightPWM(RPWM);
    setLeftPWM(LPWM);
  }
  while (RPWM < 0){
    LPWM = LPWM + 50;
    RPWM = RPWM - 80;
    setRightPWM(RPWM);
    setLeftPWM(LPWM);
  }
  setLeftPWM(0);
  setRightPWM(0);
  digitalWrite(LED, LOW);
}

void turnLeftInPlace(){
  leftTicks = 0;
  rightTicks = 0;
  int RPWM = 200;
  int LPWM = -200;
  while (rightTicks < 83){
    setRightPWM(RPWM);
    setLeftPWM(LPWM);
  }
  setLeftPWM(0);
  setRightPWM(0);
  //digitalWrite(LED, LOW);
}

void turnAround(){
  leftTicks = 0;
  rightTicks = 0;
  int RPWM = 200;
  int LPWM = -200;
  while (rightTicks < 175){
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
  while (leftTicks < 265){
    setRightPWM(RPWM);
    setLeftPWM(LPWM);
  }
  //slowDown();
  setSpeed(0,0);
}

