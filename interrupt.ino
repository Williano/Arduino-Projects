#include <arduino-timer.h>

auto timer = timer_create_default(); // create a timer with default settings

const int interruptPin = 2;

//variables to keep track of the timing of recent interrupts
volatile int rollBackVariable;
volatile int saved;

void setup() {
  // put your setup code here, to run once:
  
  attachInterrupt(digitalPinToInterrupt(interruptPin), recovery, FALLING);
  timer.every(1000, checkpoint); // call the toggle_led function every 1000 millis (1 second)
  Serial.begin(9600);  //turn on serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
  rollBackVariable = factorial(5);
  Serial.println(rollBackVariable);
  timer.tick(); // tick the timer
}

int factorial(int n) 
{ 
    // single line to find factorial 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 

void recovery() {
  Serial.println("Retrieving data....");
  Serial.println(saved);
  Serial.println("Data Retrieved.!");
}

// Interrupt service routine for interrupt 0
void checkpoint() {
  Serial.println("Saving state....");
  saved = rollBackVariable;
  Serial.println("State saved!");
}
