void setup() {

pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);

}

void loop() {

// pin 10 and 11 move one motor,
// to make the motor moves you need to have always one pin HIGH and the other LOW
  digitalWrite(10, HIGH); 
  digitalWrite(11, LOW);


// pin 12 and 13 can move a second motor, you also can connect only one
  digitalWrite(12, LOW); 
  digitalWrite(13, HIGH);

  delay(200); 

// this stop the motor
  digitalWrite(12, LOW); 
  digitalWrite(13, LOW);

  delay(200); 
  // the opposite turns the motor in the opposite direction too
  digitalWrite(12, HIGH); 
  digitalWrite(13, LOW);

 delay(200); 

// this stop the motor
  digitalWrite(12, LOW); 
  digitalWrite(13, LOW);


}

