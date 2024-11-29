#include <wiringPi.h>
#include <stdio.h>
#include <sys/time.h>

//#include "lcd.h"

#define Trig    23
#define Echo    24

#define LED 17

float measureDistance(void) 
{   
    // trig 발사
    digitalWrite(Trig, 1);
    // 10 micro seconds wait
    delayMicroseconds(10);
    // trig 끄기
    digitalWrite(Trig, 0);


    struct timeval tv1;
    struct timeval tv2;

    long start;
    long end;

    while (digitalRead(Echo) == LOW) {
        gettimeofday(&tv1, NULL);
        start = tv1.tv_sec * 1000000 + tv1.tv_usec;
    }

    while (digitalRead(Echo) == HIGH) {
        gettimeofday(&tv2, NULL);
        end = tv2.tv_sec * 1000000 + tv2.tv_usec;
    }

    float distance = (end - start) / 2000000.0 * 34300;

    return distance;
}

int main(void) 
{	
    float distance;

    struct timeval tv1;
    struct timeval tv2;

    wiringPiSetupGpio();
    
    pinMode(Echo, INPUT);
    pinMode(Trig, OUTPUT);
    pinMode(LED, OUTPUT);

    while(1) 
    {
        distance = measureDistance();
        printf("%0.2f cm\n", distance);
        
        if (distance < 10.0)
            digitalWrite(LED, 1);
        else
            digitalWrite(LED, 0);
        
        delay(1000);
    }	
    
    return 0;
}