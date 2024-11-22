#include <stdio.h>
#include <wiringPi.h>

#define GPIO_LED 4
#define GPIO_SWITCH 13

// #define HIGH 1       // defined in "wiringPi.h"
// #define LOW 0        // defined in "wiringPi.h"

int main(void) 
{
    int prevSwitchState = LOW;  // 이전 스위치 상태
    int ledState = LOW;

    wiringPiSetupGpio();

    pinMode(GPIO_LED, OUTPUT);
    pinMode(GPIO_SWITCH, INPUT);

    while(1) 
    {
        int currentSwitchState = digitalRead(GPIO_SWITCH);  // 현재 스위치 상태
        
        if (currentSwitchState == HIGH && prevSwitchState == LOW) {
            // 버튼이 눌린 경우 (LOW -> HIGH 변화 감지)
            ledState = !ledState;  // LED 상태 토글
        }
        
        prevSwitchState = currentSwitchState;  // 현재 상태를 이전 상태로 저장
        printf("current: %d, prev: %d\n", currentSwitchState, prevSwitchState);
        
        digitalWrite(GPIO_LED, ledState);
    }
}
