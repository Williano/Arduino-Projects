
#define sin_out_put_pin 5
#define cos_out_put_pin 6

void setup()
{
   Serial.begin(9600);
}

const float rad_per_deg = 0.01745329251;      // value of a radian per degree
float theta = 0;
int pulse_width_sin = 0;
int pulse_width_cos = 0;
int sign = 1;                           // to control the increments or decrements of angle parameter

void loop()
{
  analogWrite( sin_out_put_pin , pulse_width_sin );    // PWM output at the given pins
  analogWrite( cos_out_put_pin , pulse_width_cos );
  
  if (theta == 3.14159265359) sign = -1;   // keep increasing the value of theta till pi and the decrease till zero
  else if (theta == 0) sign = 1;
  
  theta = theta + (rad_per_deg * sign);
  
  pulse_width_sin = 255 * sin(theta);
  pulse_width_cos = 255 * cos(theta);

//   Serial.print(pulse_width_sin);
//   Serial.print(',');
//   Serial.print(pulse_width_cos);

  pulse_width_sin = abs(pulse_width_sin);
  pulse_width_cos = abs(pulse_width_cos);

  Serial.print(',');
  Serial.print(pulse_width_sin);
  Serial.print(',');
  Serial.println(pulse_width_cos);
  
  delay(10);  // control the frequency here
}



//#define sin_out_put_pin1 5
//#define sin_out_put_pin2 6
//
//void setup()
//{
//  Serial.begin(9600);
//}
//
//const float rad_per_deg = 0.01745329251;      // value of a radian per degree
//float theta = 0;
//int pulse_width_sin1 = 0;
//int pulse_width_sin2 = 0;
//int sign = 1;                           // to control the increments or decrements of angle parameter
//
//void loop()
//{
//  analogWrite( sin_out_put_pin1 , pulse_width_sin1 );    // PWM output at the given pins
//  analogWrite( sin_out_put_pin2 , pulse_width_sin2 );
//  
//  if (theta == 3.14159265359) sign = -1;   // keep increasing the value of theta till pi and the decrease till zero
//  else if (theta == 0) sign = 1;
//  
//  theta = theta + (rad_per_deg * sign);
//  
//  pulse_width_sin1 = 255 * sin(theta);
//  pulse_width_sin2 = 255 * sin(theta);
////
////  Serial.print(pulse_width_sin1);
////  Serial.print(',');
////  Serial.print(pulse_width_sin2);
//
//  pulse_width_sin2 = abs(pulse_width_sin1);
//  pulse_width_sin2 = abs(pulse_width_sin2);
//
//  Serial.print(',');
//  Serial.print(pulse_width_sin1);
//  Serial.print(',');
//  Serial.println(pulse_width_sin2);
//  
//  delay(10);  // control the frequency here
//}
