#include "Volume.h" // Include the Volume library
Volume vol;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT); //analog input pin from pressure
  pinMode(A1, INPUT); // ai from potentiometer
  pinMode(8, INPUT); // input from button 
  pinMode(7, OUTPUT); // output to led
  pinMode(5, OUTPUT); // output to speaker
  Serial.begin(9600); //start serial communication
  vol.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int potPin = analogRead(A1); //read signal from potentiometer
  int pressPin = analogRead(A0); // read signal from pressure sensor
  int buttonPin = digitalRead(8); //read sig from button
  Serial.println(potPin); //print potentiometer signal
  Serial.println(pressPin); //print pressure sensor signal
  Serial.println( buttonPin); //print button signal

  //BUTTON TO LED
  if(buttonPin == HIGH){
      digitalWrite(7, HIGH); //turn LED on
    }
    else{
      digitalWrite(7, LOW); //turn LED off
    }

   //PRESSURE SENSOR TO PITCH
   int newVal1 =  map(pressPin, 0 ,1023, 100, 1000); //map values to usable range for pitch
   //tone(5, newVal1, 10); //outputs tone for 10 ms with pitch from mapped value

  //POTENTIOMETER TO VOLUME
  int newVal2 = map(potPin, 0 ,1023, 0, 255); //map values to usable range for volume
  vol.tone(newVal1, newVal2);
   
}
