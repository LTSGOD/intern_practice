#include <wiringPi.h>
#include <stdbool.h>
#include <stdio.h>

int main() {

    wiringPiSetupGpio();

    pinMode(17, OUTPUT);

    while (true) {
        digitalWrite(17, 1);
        delay(1000);
        digitalWrite(17, 0);
        delay(1000);
    }
}