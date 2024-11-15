#include <stdio.h>
#include <stdlib.h>
#include "rand_between.h"

void generateRandBetween(float a, float b, int number, float result[]) {
    
    for (int i = 0; i < number; i++) {
        result[i] =  ((float)rand() / RAND_MAX) * (b - a) + a;
    }

    return;
}