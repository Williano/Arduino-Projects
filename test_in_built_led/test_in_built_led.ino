int ledOutPutPin = 8; // Declare pin to use for output.

void setup() {
  // put your setup code here, to run once:  
  pinMode(ledOutPutPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(ledOutPutPin, HIGH); // Turn the led on(HIGH is the voltage on)
  delay(1000); // Wait for 1Hz
  digitalWrite(ledOutPutPin, LOW); // Turn the led off
  delay(1000);
}
