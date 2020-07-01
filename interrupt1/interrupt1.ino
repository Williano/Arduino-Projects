
const int SIZE = 5;
const int ledPin = 13;  // LED is attached to digital pin 13
int x = 0;  // variable to be updated by the interrupt
const int interruptPin = 2;
int rollbackValues[SIZE];

//variables to keep track of the timing of recent interrupts
unsigned long button_time = 0;  
unsigned long last_button_time = 0; 
    
void setup() {
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(checkpoint), increment, RISING);
  Serial.begin(9600);  //turn on serial communication
}
    
void loop() {
  digitalWrite(ledPin, LOW);
  delay(3000); //pretend to be doing something useful
  Serial.println(x, DEC); //print x to serial monitor
  // call recovery function
  Serial.println(recovery());
}

// Interrupt service routine for interrupt 0
void checkpoint() {
  
  button_time = millis();
  //check to see if increment() was called in the last 100 milliseconds
  if (button_time - last_button_time > 100)
  {
    x++;
    digitalWrite(ledPin, HIGH);
    last_button_time = button_time;
  }
}

int recovery() {

  for (byte i = 0; i < SIZE; i = i + 1) {
    
    Serial.println(rollbackValues[i]);
   }

}
//
//void* recovery() {
//
//  return rollbackValues;
//}
