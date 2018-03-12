#include <Stepper.h>
// Sources:
// https://stargazerslounge.com/topic/160813-arduino-uno-r3-arduino-motor-shield-r3-genuine/
// http://www.instructables.com/id/Arduino-Motor-Shield-Tutorial/
// https://www.arduino.cc/en/Tutorial/StepperSpeedControl
const int stepsPerRevolution = 200; // change this to fit the number of steps per revolution

// for your motor

// initialize the stepper library on the motor shield

Stepper myStepper(stepsPerRevolution, 12,13);

int sensorValue = 0;        // value read from the pot
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

// give the motor control pins names:

const int pwmA = 3;

const int pwmB = 11;

const int brakeA = 9;

const int brakeB = 8;

const int dirA = 12;

const int dirB = 13;

int x = 0;

void setup () {

Serial.begin(9600);

// set the PWM and brake pins so that the direction pins // can be used to control the motor:

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

myStepper.setSpeed(60);

} void loop () {

  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  int motorSpeed = map(sensorValue, 0, 690, 
);
    
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }
}
