// Sources:
// https://www.arduino.cc/en/Reference/StepperConstructor
// https://www.sdrobots.com/tech-thursday-021-arduino-stepper-motor-control/

#include <Stepper.h>
#include "TimerOne.h"

const int stepsPerRevolution = 200; // change this to fit the number of steps per revolution
Stepper myStepper(stepsPerRevolution, 12,13);
int stepCount = 0;  // number of steps the motor has taken
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the Servo (position or angle)
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

// give the motor control pins names:
const int pwmA = 3;
const int pwmB = 11;
const int brakeA = 9;
const int brakeB = 8;
const int dirA = 12;
const int dirB = 13;
int x = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(brakeB, OUTPUT);
  digitalWrite(pwmA, HIGH);
  digitalWrite(pwmB, HIGH);
  digitalWrite(brakeA, LOW);
  digitalWrite(brakeB, LOW);
  // initialize the serial port:
  Serial.begin(9600);
  // set the motor speed (for multiple steps only):
}

void loop() {
  // put your main code here, to run repeatedly:
  // set the PWM and brake pins so that the direction pins // can be used to control the motor:
   // read the analog in value:
  sensorValue = analogRead(analogInPin);
  
  // map it to the range of the analog out:
  // Mapping analog input from 0 to 690 to 0 to 80 speed (didn't want to go to 100)
  int motorSpeed = map(sensorValue, 0, 690, 0, 80); 
    
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }
}
