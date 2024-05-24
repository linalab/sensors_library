int miLed = 13;  // pin conectado a un led
int pinA = A0;   // conectado a un pin analógico
int pinD = 4;    // Conectado a un pin digital
int valA;        // variable que cambiara entre 0 y 1 de acuerdo al umbral del potenciómetro del micro
int valD;        // variable que cambiará entre 0 y 1023 de acuerdo al ruido

void setup() {
  Serial.begin(9600);       // inicializamos la conexión serial entre ordenador y Arduino
  pinMode(miLed, OUTPUT);   // presentamos al pin del led como OUTPUT
  pinMode(pinA, INPUT);  // presentamos al pin digital del sensor como INPUT
  pinMode(pinD, INPUT);  // presentamos al pin analógico del sensor como INPUT
  digitalWrite(miLed, LOW);  // comenzamos el código con el led apagado
}

void loop() {
  val = analogRead(pinA);  // leemos el valor analógico del micro
  sensorD = digitalRead(sensor);  // leemos el valor digital del micro
  Serial.print("Pin Analógico= ");
  Serial.println(val);// imprimimos el valor digital del micro
  Serial.print("Pin Digital= ");
  Serial.println(sensorD); // imprimimos el valor digital del micro
  delay(200);


  if (val >= 600) {             // si el ruido supera el umbral de 600 ...
    digitalWrite(miLed, HIGH);  // entonces led on
    delay(1000);
  } else { // si no supera el umbral ... 
    digitalWrite(miLed, LOW); // entonces led off
  }
}
