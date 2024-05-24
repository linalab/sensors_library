/* En este ejemplo encendemos una tira led de 8 píxeles
WS2812
*/

/// @file    Blink.ino
/// @brief   Blink the first LED of an LED strip
/// @example Blink.ino

#include <FastLED.h>

#define NUM_LEDS 8  // Especificamos el número de leds
#define DATA_PIN 5

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  // Uncomment/edit one of the following lines for your leds arrangement.
  // ## Clockless types ##
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
}

void loop() {

  /* Para encender un led de un color, necesitamos específicar
el número de píxel, y la cantidad de color en R, G, y B.
Por ejemplo, encendemos el led 0, en rojo. es decir R 255, G 0 y B 0.
  */
  leds[0].r = 255;  // al led 0 le enviamos rojo a 255
  leds[0].g = 0;    // al led 0 le enviamos verde a 0
  leds[0].b = 0;    // al led azul le enviamos azul a 0
  FastLED.show();   // esta instrucción hace que esta información la reciba el pixel
  delay(500);       // tiempo de espera antes de cambiar a otra instrucción

  // La siguiente instrucción apaga el led, es decir le eviamos el valor de 0
  leds[0] = 0;     // si no especificamos r, g o b, entonces todos los canales reciben el valor
  FastLED.show();  //
  delay(500);
}
