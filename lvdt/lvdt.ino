void setup()
{
Serial.begin(9600); 
pinMode(A0,INPUT); 
pinMode(A1,INPUT);
}
void loop()
{
  float secondary1 =0;
  float secondary2 =0; 
  float secondary12 = 0; 
  float secondary22 = 0; 
  float secondary13 = 0; 
  float secondary23 = 0;

  float dis = 0;
  int wave;

// for(int i =0; i<=40; i++)
// {
//   secondary1 = sq(3.3 - analogRead(A0)*0.0048); 
//   secondary2 = sq(3.3 - analogRead(A1)*0.0048); 
//   secondary12 =secondary12+secondary1; 
//   secondary22 =secondary22+secondary2; 
//   delay(0.5);
// }
//   secondary13 =sqrt(secondary12/40); 
//   secondary23 =sqrt(secondary22/40);
//   dis = (125*(secondary13 - secondary23)); 
//  //Serial.println(dis);
//  Serial.println(analogRead(A0));
//  Serial.println(analogRead(A1));

  Serial.println(analogRead(A0));
  delay(10);
  Serial.println(analogRead(A1));
 
 
}
