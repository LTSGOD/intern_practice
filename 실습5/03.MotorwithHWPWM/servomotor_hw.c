#include <stdio.h>
#include <wiringPi.h>
#include <time.h>

#define PIN 18
#define PWM_CLOCK_DIVISOR 384   // This will generate 50,000 Hz from 19.2 MHz clock source
#define PWM_RANGE 1024          // The total number of clock ticks during a period
                                // This is equivalent to a period of 20 ms

void moveMotor(int degree)
{
    float dutyCycle;        // the unit is %
    int pulseWidth;         

    /////////////////////////////////////////////////////////////////////
    // Insert your code here
    /////////////////////////////////////////////////////////////////////
    dutyCycle = 5.0 + (degree / 180.0) * 5.0; // 5% (0도) ~ 10% (180도)

    // SG모터 스펙
    // 50Hz, 주기 20ms
    // -90(0) -> ~1ms pulse(5% 듀티 사이클)
    // 0(90) -> 1.5ms pulse(7.5% 듀티 사이클)
    // +90(180) -> ~2ms pulse(10% 듀티 사이클)
    
    // PWM_RANGE와 dutyCycle을 사용해 pulseWidth 계산
    pulseWidth = (int)(dutyCycle * PWM_RANGE / 100.0);

    printf("dutyCycle = %.1f%%\n", dutyCycle);
    printf("pulseWidth = %d\n", pulseWidth);

    // PWM 신호 출력
    pwmWrite(PIN, pulseWidth);
}

int main(void) 
{
    int inputValue;

    wiringPiSetupGpio();

    /////////////////////////////////////////////////////////////////////
    // Insert your code here
    // Your code should initialize PWM by using the following functions
    // --> pinMode(), pwmSetMode(), pwmSetClock(), pwmSetRange()
    /////////////////////////////////////////////////////////////////////
        
    pinMode(PIN, PWM_OUTPUT); // PWM OUTPUT으로 설정
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(PWM_CLOCK_DIVISOR);
    pwmSetRange(PWM_RANGE);
    
    while(1) 
    {
        printf("Enter value: ");
        scanf("%d", &inputValue);
        
        moveMotor(inputValue);
        
        delay(600);
    }    
    
    return 0;
}
