#include <stdio.h>
#include "Bitwise.h"

typedef union {
    float f;
    unsigned u;
    struct {
        unsigned mantissa: 23;
        unsigned exponent: 8;
        unsigned sign: 1;
    } raw;
} ufloat;

int main() {

    ufloat value;

    printf("Enter a float number: ");
    scanf("%f", &(value.f));

    printf("\nBreakdown of %f\n: ", value.f);
    printBinary(value.raw.sign, 1);
    printf("   ");
    printBinary(value.raw.exponent, 8);
    printf("   ");
    printBinary(value.raw.mantissa, 23);

    printf("\nSign: ");
    printBinary(value.raw.sign, 1);
    printf("\nExponent: ");
    printBinary(value.raw.exponent, 8);
    printf("\nMantissa: ");
    printBinary(value.raw.mantissa, 23);

    return 0;
}