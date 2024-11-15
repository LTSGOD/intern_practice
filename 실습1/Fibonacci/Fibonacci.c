#include <stdio.h>

long int fibonacci(int number);
long int fibonacci_loop(int number);

int callCount;

int main() {

    int n;

    printf("Enter a number up to which Fibonacci series are computed: ");
    scanf("%d", &n);

    printf("\nFibonacci series computed by recursion.");
    printf("\nFib   Value    # of Calls");
    
    for (int i = 0; i <= n; i++) {
        callCount = 0;
        int value = fibonacci(i);
        printf("\nFib(%d)    %d     %d", i, value, callCount);
    }

    printf("\nFibonacci series computed by loop.");
    for (int i = 0; i <= n; i++) {
        callCount = 0;
        int value = fibonacci_loop(i);
        printf("\nFib(%d)    %d     %d", i, value, callCount);
    }
    return 0;
}

long int fibonacci(int number) {
    callCount++;
    if (number == 0 || number == 1) return number;
    if (number == 2) return 1;
    return fibonacci(number - 2) + fibonacci(number - 1);
}

long int fibonacci_loop(int number) {
    int fib[100];
    fib[0] = 0;
    fib[1] = 1;

    callCount++;

    for (int i = 2; i <= number; i++) {
        fib[i] = fib[i -2] + fib[i - 1];
    }

    return fib[number];
}