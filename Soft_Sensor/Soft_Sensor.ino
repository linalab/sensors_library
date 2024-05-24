/* Reading the values of a soft sensor */

int sensorPin = A0;  // select the input pin for the potentiometer
int sensorValue;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
}
