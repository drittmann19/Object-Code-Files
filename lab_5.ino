
const int buttonPin = 2;
const int motor1Pin = 3;
const int motor2Pin = 4;
const int enablePin = 9;
int button = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  //digitalWrite(enablePin, HIGH);
  Serial.begin(9600); //start serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
  button = digitalRead(buttonPin);
  Serial.println(button);

  if(button == HIGH){
    digitalWrite(motor1Pin, LOW);
    digitalWrite(motor2Pin, HIGH);
  }
  else{
    digitalWrite(motor1Pin, HIGH);
    digitalWrite(motor2Pin, LOW);
  }
  
}
