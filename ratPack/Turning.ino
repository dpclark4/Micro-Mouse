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
