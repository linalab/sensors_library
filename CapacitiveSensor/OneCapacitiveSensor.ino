/*******************************************************************************

 Bare Conductive Capacitive Proximity Sensor
 -------------------------------------------

 For Arduino boards. Use a large resistor, about 1M between pin 2 and 4 and
 connect pin 2 to a sensor, for example Electric Paint.

 Based on code by Paul Badger.

 Bare Conductive code written by Pascal Loose

 This work is licensed under a MIT license https://opensource.org/licenses/MIT

 Copyright (c) 2020, Bare Conductive

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

*******************************************************************************/

// capacitive sensing includes
#include <CapacitiveSensor.h>

// capacitive sensing constant
CapacitiveSensor sensor = CapacitiveSensor(4,2);  // 1M resistor between pins 4 & 2, pin 2 is sensor pin

void setup() {
  Serial.begin(115200);
}

void loop() {
  long measurement =  sensor.capacitiveSensor(30);
  
  Serial.println(measurement);
  delay(10);
}
