void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(9, 64);
  delay(1000);
  analogWrite(9, 127);
  delay(1000);
  analogWrite(9, 191);
  delay(1000);
  analogWrite(9, 255);
  delay(1000);
  analogWrite(9, 0);
  delay(1000); 

}
