#include <arduino-timer.h>

auto timer = timer_create_default(); // create a timer with default settings
const int interruptPin = 2;
volatile int rollBackVariable;
volatile int saved;
unsigned long button_time = 0;  
unsigned long last_button_time = 0; 

void setup() {
  attachInterrupt(digitalPinToInterrupt(interruptPin), recovery, FALLING);
  timer.every(1, checkpoint); // call the toggle_led function every 1000 millis (1 second)
  Serial.begin(9600);  //turn on serial communication
}

void loop() {
  timer.tick(); // tick the timer
  Serial.println(factorial(5));
  delay(100);
}

int factorial(int n) 
{ 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 

void recovery() {
  cli();
  malicious(); // This is a function that I will write it later.
               // I will not tell you what I will be doing in this function, it is going to 
               // destroy some registers of the processor.
               // The idea is that the checkpoint/recovery should be able to cancel this function out.
  //******************************* 
       //Implement the actual recovery here: you should restor all registers 
       //from what you saved in the checkpoint funciton. 
  //******************************* 
  Serial.print("Recovery done at the time:");
  Serial.println(micros());
  sei();    
  }    
}

void checkpoint() {
  //At this routine you should save all register somewhere in memory for later recovery 
}

void malicious(void){
  //I will do some malicious things here to destroy some of your registers. 
  //Your code should stand it. 

}
