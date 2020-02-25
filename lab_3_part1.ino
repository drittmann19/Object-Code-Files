void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT); //analog input pin from potentiometer
  pinMode(A1, INPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600); //start serial communication
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int potPin = analogRead(A0); //read signal from potentiometer
  int pressPin = analogRead(A1); // read signal from pressure sensor
  Serial.println(potPin); //print potentiometer signal
  Serial.println(pressPin); //print pressure sensor signal

  //map the values to a usuable range for outputs
  //int newVal = map(potentiometerLow, potentiometerHigh, newHigh, newLow);
  // map(val, 0 ,1023, 0, 255); //0-255 is a usable range for an LED
  int newVal1 =  map(potPin, 0 ,1023, 0, 255); //map values to usable range for LEDs
  analogWrite(5, newVal1);

  int newVal2 = map(pressPin, 0 ,1023, 0, 255); //map values to usable range for LEDs
  analogWrite(3, newVal2);
}
