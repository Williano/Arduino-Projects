#include <MegunoLink.h>
int Output1 = 11;
int var1 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Output1, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int d = 0; d < 360; d++) {
    Serial.print(2);
    Serial.print(" ");
    Serial.print(-2);
    Serial.print(" ");
  
    Serial.println(sin(DEG_TO_RAD *d));
    //analogWrite(Output1, sin(DEG_TO_RAD *d));
    }
}
