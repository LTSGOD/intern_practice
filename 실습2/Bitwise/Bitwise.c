#include <stdio.h>
#include "Bitwise.h"

#define MAX 100

int getNthBitFromLSB(int number, int nthBit) {

    return (number & (1 << (nthBit))) ? 1 : 0;
}

void setNthBitFromLSB(int* number, int nthBit) {
    *number |= (1 << (nthBit));
    printf("number %d", *number);
}

void clearNthBitFromLSB(int* number, int nthBit) {
    *number &= ~(1 << (nthBit));
}

int countOne(int number) {
    int count = 0;
    int share = number;

    // stack 이진수 넣기
    while ((share != 0)) {
        if (share % 2 == 1) count++;
        share /= 2;
    }

    return count;
}

void printBinary(int number, int nbitsToPrint) {
    int stack[MAX];
    int index = 0;

    int share = number;

// stack 이진수 넣기
    while ((share != 0)) {
        stack[index++] = share % 2;
        share /= 2;
    }

// 이진수 nbits 포맷 맞게 출력
    int bit_counter = 4 - nbitsToPrint % 4;
    for (int i = nbitsToPrint; i > 0; i--) {
        if (i != index) {

            if (bit_counter == 4) {
                bit_counter = 0;
                printf(" ");
            }
            bit_counter++;
            printf("0");
        } else {
            if (bit_counter == 4) {
                bit_counter = 0;
                printf(" ");
            }
            bit_counter++;
            printf("%d", stack[--index]);
        }
    }
}
