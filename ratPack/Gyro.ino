
void readGyro() {
  float gyroVoltage = 3.3;         //Gyro is running at 5V
  float gyroSensitivity = .0039;  //Our example gyro is 7mV/deg/sec
  float rotationThreshold = 2;   //Minimum deg/sec to keep track of - helps with gyro drifting

float currentAngle = 0;          //Keep track of our current angle

  //This line converts the 0-1023 signal to 0-5V
  float gyroRate = ((analogRead(A14) - .995*analogRead(A3)) * gyroVoltage) / 1023;

  //This line divides the voltage we found by the gyro's sensitivity
  gyroRate /= gyroSensitivity;

  //Ignore the gyro if our angular velocity does not meet our threshold
  if (gyroRate >= rotationThreshold || gyroRate <= -rotationThreshold) {
    //This line divides the value by 100 since we are running in a 10ms loop (1000ms/10ms)
    gyroRate /= 1000;
    angle += gyroRate;
  }

}
