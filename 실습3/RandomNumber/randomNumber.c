#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rand_between.h"

#define MAX 1024

int main() {
    float a, b;
    int number;
    float result[MAX];

    printf("Enter a start value of range: ");
    scanf("%f", &a);

    printf("Enter a finish value of range: ");
    scanf("%f", &b);

    printf("Enter the total number of random values to generate: ");
    scanf("%d", &number);

    srand(time(NULL));

    printf("Random Value in [%f, %f]\n", a, b);

    generateRandBetween(a, b, number, result);

    for (int i = 0; i < number; i++) {
        printf("%f ", result[i]);
    }

    return 0;
}
