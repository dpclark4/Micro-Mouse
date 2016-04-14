void setupMotors() {
  // Define Motor Pins as Outputs
  analogWriteResolution(11);
  for (int i = 0; i < 4; i++) {
    analogWriteFrequency(motorPins[i], 23437);
    pinMode(motorPins[i], OUTPUT);
  }
  
  // Define Encoder Pins as Inputs
  for (int i = 0; i < 4; i++) {
    pinMode(encoderPins[i], INPUT);
  }
  
  // Encoder Interrupt Setups
  attachInterrupt(ER1, rightEncoder1, RISING);
  attachInterrupt(ER2, rightEncoder2, RISING);
  attachInterrupt(EL1, leftEncoder1, RISING);
  attachInterrupt(EL2, leftEncoder2, RISING);
}

void setLeftPWM(int value) {
  if (value > 600 || value < -600) {
    ;
  }
  
  else if (value >= 0) {
    analogWrite(ML1, 2047);
    analogWrite(ML2, 2047 - value);
  } else {
    analogWrite(ML2, 2047);
    analogWrite(ML1, 2047 + value);
  }
}

void setRightPWM(int value) {
  if (value > 600 || value < -600) {
    ;
  }
  else if (value >= 0) {
    analogWrite(MR1, 2047);
    analogWrite(MR2, 2047 - value);
  } else {
    analogWrite(MR2, 2047);
    analogWrite(MR1, 2047 + value);
  }
}
// Right Encoder ISR
void rightEncoder1() {
  if (digitalReadFast(ER2) == LOW) {
    rightTicks++;
  }
  else {
    rightTicks--;
  }
}


void rightEncoder2() {
  if (digitalReadFast(ER1) == HIGH) {
    rightTicks++;
  }
  else {
    rightTicks--;
  }
}


// Left Encoder ISR
void leftEncoder1() {
  if (digitalReadFast(EL2) == HIGH) {
    leftTicks++;
  }
  else {
    leftTicks--;
  }
}

void leftEncoder2() {
  if (digitalReadFast(EL1) == LOW) {
    leftTicks++;
  }
  else {
    leftTicks--;
  }
}

