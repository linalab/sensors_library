int miLed = 13;  // pin conectado a un led
int pin = A0;   // conectado a un pin analógico
int val;        // variable que cambiará entre 0 y 1023 de acuerdo al ruido

void setup() {
  Serial.begin(9600);       // inicializamos la conexión serial entre ordenador y Arduino
  pinMode(miLed, OUTPUT);   // presentamos al pin del led como OUTPUT
  pinMode(pin, INPUT);  // presentamos al pin digital del sensor como INPUT
  digitalWrite(miLed, LOW);  // comenzamos el código con el led apagado
}

void loop() {
  val = analogRead(pin);  // leemos el valor analógico del micro
  Serial.print("Pin Analógico= ");
  Serial.println(val);// imprimimos el valor digital del micro
  delay(200);


  if (val >= 600) {             // si el ruido supera el umbral de 600 ...
    digitalWrite(miLed, HIGH);  // entonces led on
    delay(1000);
  } else { // si no supera el umbral ... 
    digitalWrite(miLed, LOW); // entonces led off
  }
}
