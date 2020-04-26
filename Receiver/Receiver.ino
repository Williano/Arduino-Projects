char mystr[10]; //Initialized variable to store recieved data
int ledOutPutPin = 8;
int data; 

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {
  data = Serial.readBytes(mystr,5)- '0'; //Read the serial data and store in var
  Serial.println(data); //Print data on Serial Monitor
  digitalWrite(ledOutPutPin, HIGH); // Turn the led on(HIGH is the voltage on)
  delay(1000); // Wait for 1Hz
  digitalWrite(ledOutPutPin, LOW); // Turn the led off
  delay(1000);
}
