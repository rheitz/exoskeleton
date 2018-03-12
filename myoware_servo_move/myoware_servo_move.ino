/* Button move Servo
 by Ryan Heitz
 This example code is in the public domain.

 created 17 Feb 2018
 Sources:
 Modified from 
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
Servo myservo1;  // create servo object to control a servo

// constants won't change. They're used here to set pin numbers:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

// variables will change:
int posServo1 = 0;    // variable to store the servo position
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the Servo (position or angle)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // attaches the servo on pin 9 to the servo object
  myservo1.attach(9);  

}

void loop() {
  // put your main code here, to run repeatedly:
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out: in this case map  0 to 690 to 10 to 170 degrees
  outputValue = map(sensorValue, 0, 690, 10, 170);
  myservo1.write(outputValue); 
  delay(15); 
  
  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
  
}
