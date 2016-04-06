#pragma once

const int ML1 = 6;
const int ML2 = 5;
const int MR1 = 9;
const int MR2 = 10;
const int ER1 = 14;
const int ER2 = 12;
const int EL1 = 15;
const int EL2 = 16;

// Motor Pins
const int motorPins[] = {MR1, MR2, ML1, ML2};

// Encoder Pins
const int encoderPins[] = {ER1, ER2, EL1, EL2};

int currentRightPWM = 0;
int currentLeftPWM = 0;

// Encoder Ticks
volatile int rightTicks = 0;
volatile int leftTicks = 0;

