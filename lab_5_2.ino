
#include <Stepper.h>

const int stepsPerRevolution = 50;  //number of steps per revolution

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // set the speed
  myStepper.setSpeed(75);
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
