/****************************************
Example Sound Level Sketch for the 
Adafruit Microphone Amplifier

Circuit:
GND -> GND
VCC -> 3.3V
OUT -> AIN0
// Gain Adjustments:
GAIN -> VCC ( 50dB )
GAIN -> GND ( 40dB )
GAIN -> Disconnected (60 dB )

Tutorial: https://learn.adafruit.com/adafruit-microphone-amplifier-breakout/measuring-sound-levels
Adapted by Citlali Hernández 2024
****************************************/
int ledPin = 3;
float valMap;
float voltsf;

const int sampleWindow = 50;  // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}


void loop() {
  unsigned long startMillis = millis();  // Start of sample window
  unsigned int peakToPeak = 0;           // peak-to-peak level

  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow) {
    sample = analogRead(0);
    if (sample < 1024)  // toss out spurious readings
    {
      if (sample > signalMax) {
        signalMax = sample;  // save just the max levels
      } else if (sample < signalMin) {
        signalMin = sample;  // save just the min levels
      }
    }
  }
  peakToPeak = signalMax - signalMin;        // max - min = peak-peak amplitude
  double volts = (peakToPeak * 5.0) / 1024;  // convert to volts


  valMap = map(volts, 0, 3, 0, 255);
  analogWrite(ledPin, valMap);

/*
  Serial.print("Amplitud= ");
  Serial.print(volts);
  Serial.print(" . . . . . . . ");
  Serial.print("ValMap= ");
  Serial.println(valMap);
*/

// Podemos definir umbrales y controlar comportamientos de acuerdo a ellos
  if(volts<0.3){ 
    Serial.println("Volumen Bajo");
  } 
   if((volts>0.3) && (valMap<1.3)){
    Serial.println("Volumen Medio");
  } 
   if(volts>1.3){
    Serial.println("Volumen Alto");
  } 

}
