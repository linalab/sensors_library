int const PULSE_SENSOR_PIN = 0;   // 'S' Signal pin connected to A0

int Signal;                // Store incoming ADC data. Value can range from 0-1024

void setup() {
	pinMode(13, OUTPUT);  // 
	Serial.begin(9600);           // Set comm speed for serial plotter window
}

void loop() {

	Signal = analogRead(PULSE_SENSOR_PIN); // Read the sensor value

	Serial.println(Signal);                // Send the signal value to serial plotter

	if(Signal > 550){                // If the signal is above threshold, turn on the LED
		digitalWrite(13, HIGH);
	} else {
		digitalWrite(13, LOW);     // Else turn off the LED
	}
	delay(10);
}