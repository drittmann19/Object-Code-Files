void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT); //analog input from photoresistors
  pinMode(6, OUTPUT); // analog output to speaker
  Serial.begin(9600); //start serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
  int photoPin = analogRead(A0); //read signal from photoresistors
  Serial.println(photoPin); //print signal from photoresistor

  int newVal =  map(photoPin, 0 ,1023, 100, 1000); //map values to usable range for pitch
  tone(6, newVal, 10); //outputs tone for 10 ms with pitch from mapped value
}
