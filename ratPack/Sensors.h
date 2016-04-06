#pragma once

#define left 0
#define diagl 1
#define lf 2
#define rf 3
#define right 4
#define diagr 5

// IR Pair Pins    B   G   G   B   G  G
const int TX[6] = {8,  2,  7,  11, 1, 0};
//                     
const int RX[6] = {A5, A9, A6, A7, A4, A8};

volatile int leftSensor;
volatile int rightSensor;
volatile int rightMiddle;
volatile int leftMiddle;
volatile int leftFront;
volatile int rightFront;
