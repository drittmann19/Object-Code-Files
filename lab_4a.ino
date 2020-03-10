int incoming;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly

  int pot1 = analogRead(A0);
  int pot2 = analogRead(A1);

  //formatting is important with going to p5
  Serial.print(pot1);
  Serial.print(",");
  Serial.println(pot2);
  delay(1);


  if(Serial.available() > 0){
    incoming = Serial.read();

    if(incoming == 0){
      digitalWrite(12, LOW);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      digitalWrite(4, LOW);
    }
    if(incoming == 1){
      digitalWrite(12, HIGH);
    }else if(incoming == 2){
      digitalWrite(8, HIGH);
    }else if(incoming == 3){
      digitalWrite(7, HIGH);
    }else if(incoming == 4){
      digitalWrite(4, HIGH);
    }
  }
}
