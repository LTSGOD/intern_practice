#include <stdio.h>
#include <wiringPi.h>

#define GPIO_LED 4
#define GPIO_SWITCH 13

// #define HIGH 1       // defined in "wiringPi.h"
// #define LOW 0        // defined in "wiringPi.h"

int main(void) 
{
    int switchState;
    int ledState = LOW;

    wiringPiSetupGpio();

    pinMode(GPIO_LED, OUTPUT);
    pinMode(GPIO_SWITCH, INPUT);
    
    
    while(1) 
    {
    
        // Insert your code here
        if (digitalRead(GPIO_SWITCH)) {
            ledState = !ledState;

            delay(300);
        }

        // printf("%d", ledState);
            
        digitalWrite(GPIO_LED, ledState);
        
    }
}
