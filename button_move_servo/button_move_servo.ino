/* Button move Servo
 by Ryan Heitz
 This example code is in the public domain.

 created 17 Feb 2018
 Sources:
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int posServo1 = 0;    // variable to store the servo position
int posServo2 = 0;    // variable to store the servo position

void setup() {
  // put your setup code here, to run once:
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // attaches the servo on pin 9 to the servo object
  myservo1.attach(9);  
  myservo2.attach(10);  

}

void loop() {
  // put your main code here, to run repeatedly:
// read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    myservo1.write(135); 
    delay(15); 
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    myservo1.write(45); 
    delay(15);
  }
}
