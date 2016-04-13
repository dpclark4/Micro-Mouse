void setupSensors() {
  // Define IR Pair TXs as Outputs
  for (int i = 0; i < 6; i++) {
    pinMode(TX[i], OUTPUT);
    digitalWriteFast(TX[i], LOW);
  }
  analogReadResolution(12);
  analogReadAveraging(4);
}

void readSensors() {
  static int leftFrontAmbient = 0;
  static int rightFrontAmbient = 0;
  static int leftSensorAmbient = 0;
  static int rightSensorAmbient = 0;
  static int leftMiddleAmbient = 0;
  static int rightMiddleAmbient = 0;

//Read ambient values.
        leftFrontAmbient = analogRead(RX[lf]);
        leftMiddleAmbient = analogRead(RX[diagl]);
        rightMiddleAmbient = analogRead(RX[diagr]);

        digitalWriteFast(TX[lf],HIGH);
        delayMicroseconds(80);
        leftFront = analogRead(RX[lf]) - leftFrontAmbient;
        digitalWriteFast(TX[lf],LOW);
        delayMicroseconds(60);

        rightFrontAmbient = analogRead(RX[rf]);
        
        digitalWriteFast(TX[rf],HIGH);
        delayMicroseconds(80);
        rightFront = analogRead(RX[rf]) - rightFrontAmbient;
        digitalWriteFast(TX[rf],LOW);
        delayMicroseconds(60);
        
        leftSensorAmbient = analogRead(RX[left]);
        rightSensorAmbient = analogRead(RX[right]);
        digitalWriteFast(TX[left],HIGH);
        digitalWriteFast(TX[right],HIGH);
        delayMicroseconds(80);
        rightSensor = analogRead(RX[right]) - rightSensorAmbient;
        leftSensor = analogRead(RX[left]) - leftSensorAmbient;
        delayMicroseconds(60);
        digitalWriteFast(TX[left],LOW);
        digitalWriteFast(TX[right],LOW);

        //leftMiddleAmbient = analogRead(RX[diagl]);
        //rightMiddleAmbient = analogRead(RX[diagr]);
        digitalWriteFast(TX[diagl],HIGH);
        digitalWriteFast(TX[diagr],HIGH);
        delayMicroseconds(80);
        leftMiddle = analogRead(RX[diagl]);// - leftMiddleAmbient;
        rightMiddle = analogRead(RX[diagr]);// - rightMiddleAmbient;
        digitalWriteFast(TX[diagl], LOW);
        digitalWriteFast(TX[diagr], LOW);
        delayMicroseconds(60); 
}

