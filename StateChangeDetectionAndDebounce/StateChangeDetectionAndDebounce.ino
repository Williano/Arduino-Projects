/*
 * Sketch: StateChangeDetectionAndDebounce
 * Description: A Sketch in C to count the number of time a button is pressed using the Pin Change interrupt of AVR, 
 *              debounces the switch and show the count number on the serial monitor of Arduino. U
 * Author: William Kwabla
 * Date: 04/22/20
*/

const int buttonPin = 4;    // the number of the pushbutton pin

// Variables will change
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
int buttonPushCounter = 0;   // counter for the number of button presses

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  // initialize the button pin as a input
  pinMode(buttonPin, INPUT);

  // initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // read the state of the switch into a local variable
  int reading = digitalRead(buttonPin);

  // If the switch changed, due to noise or pressing
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    // if the button state has changed
    if (reading != buttonState) {
      buttonState = reading;

  if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on
      buttonPushCounter++;
      Serial.println("ON");
      Serial.print("Number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off
      Serial.println("OFF");
    }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}
