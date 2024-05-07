int LEDS = 3; 
int pinA = A1; 
int val;

void setup(){
  Serial.begin(9600);
  pinMode(LEDS, OUTPUT);
  pinMode(sensor , INPUT_PULLUP); 
  digitalWrite(LEDS, LOW); // 
}

void loop(){
  val = analogRead(pinA); // reads the value of the sensor

  if ( val >= 700 ){ // if it's higher than 700 then
    digitalWrite(LEDS, HIGH); // turn on the leds 
    delay (1000);
  }
  else{
    digitalWrite(LEDS, LOW); 
  }

  Serial.println(val);
}