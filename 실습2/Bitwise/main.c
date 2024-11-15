#include <stdio.h>
#include "Bitwise.h"

int main() {
    int n;
    int bitPos;
    
    printf("Enter an int number: ");
    scanf("%d", &n);

    printf("%d (in decimal) ");
    printBinary(n, 32);

    printf("The number of '1's is %d\n\n", countOne(n));

    printf("Enter a bit position to experiment with (from LSB): ");
    scanf("%d", &bitPos);

    setNthBitFromLSB(&n, bitPos);
    printf("\n\nAfter setting %dth bit: %d (in decimal)\n", bitPos, n);
    printBinary(n, 32);

    printf("\nThe %dth bit is %d\n\n", bitPos, getNthBitFromLSB(n, bitPos));

    clearNthBitFromLSB(&n, bitPos);
    printf("\nAfter clearing %dth bit: %d (in decimal)\n", bitPos, n);
    printBinary(n, 32);

    printf("\nThe %dth bit is %d\n\n", bitPos, getNthBitFromLSB(n, bitPos));

    return 0;
}