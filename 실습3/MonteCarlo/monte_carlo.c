#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include "rand_between.h"

#define NUM_MAX 100000

int count[4] = {0, 0, 0, 0};

void* simulateMonteCarlo(void* quadrant)
{

    float result_x[NUM_MAX];
    float result_y[NUM_MAX];

    generateRandBetween(-1, 1, NUM_MAX, result_x);
    generateRandBetween(-1, 1, NUM_MAX, result_y);

    for (int i = 0; i < NUM_MAX; i++) {
        if (result_x[i] * result_x[i] + result_y[i] * result_y[i] <= 1) {
            count[*(int*)quadrant - 1]++;
        }
    }

    return NULL;
    // Insert your code here
}

int main(void)
{   
    int i;
    pthread_t threads[4];
    int quadrantNumer[4] = {1, 2, 3, 4};
    int sum = 0;
    double pi;
    int threadReturn;

    for(i = 0; i < 4; i++)
    {
        pthread_create(&threads[i], NULL, simulateMonteCarlo, &quadrantNumer[i]);
    }

    for (i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL);
    }

    sum = count[0] + count[1] + count[2] + count[3];
    pi = (double) sum / (NUM_MAX);

    printf("Counts: %d %d %d %d\n", count[0], count[1], count[2], count[3]);
    printf("Sum of counts: %d\n", sum);
    printf("The value of PI is %f\n", pi);

    return 0;
}