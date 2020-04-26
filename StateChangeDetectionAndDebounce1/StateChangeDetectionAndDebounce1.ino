/*
 * Sketch: StateChangeDetectionAndDebounce
 * Description: A Sketch in C to count the number of time a button is pressed using the Pin Change interrupt of AVR, 
 *              debounces the switch and show the count number on the serial monitor of Arduino. U
 * Author: William Kwabla
 * Date: 03/25/20
*/

// this constant won't change:
const int  buttonPin = 4;    // the pin that the pushbutton is attached to

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);

  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(500);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

}
