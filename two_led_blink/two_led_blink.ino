/*
 * Sketch: two_led_blink
 * Description: A Sketch in C to let two LEDs connected to an output pin blinking in opposite.
 * Author: William Kwabla
 * Date: 02/21/20
*/


int firstLedOutPutPin = 7; // Declare pin to use for first LED output.
int secondLedOutPutPin = 10; // Declare pin to use for second LED output.

void setup() {
 
  pinMode(firstLedOutPutPin, OUTPUT);
  pinMode(secondLedOutPutPin, OUTPUT);

}

void blink(const int ledPinNumber) {
  
  digitalWrite(ledPinNumber, HIGH); // Turn the LED on.
  delay(1000); // Wait for 1Hz
  digitalWrite(ledPinNumber, LOW); // Turn the LED off.
  delay(1000);
 }

void loop() {
  blink(firstLedOutPutPin);
  blink(secondLedOutPutPin);
}
