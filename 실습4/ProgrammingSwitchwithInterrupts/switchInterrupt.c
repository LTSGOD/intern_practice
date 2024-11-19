#include <stdio.h>
#include <wiringPi.h>

#define GPIO_LED 4
#define GPIO_SWITCH 13

// #define HIGH 1       // defined in "wiringPi.h"
// #define LOW 0        // defined in "wiringPi.h"

void interruptHandler();

int ledState = LOW;

int main(void) 
{

    wiringPiSetupGpio();

    pinMode(GPIO_LED, OUTPUT);
    pinMode(GPIO_SWITCH, INPUT);

    wiringPiISR(GPIO_SWITCH, INT_EDGE_RISING, interruptHandler);
    
    
    while(1) 
    {
        digitalWrite(GPIO_LED, ledState);
    }
}

void interruptHandler() {
    ledState = !ledState;
}