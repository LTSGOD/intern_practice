#ifndef BITWISE_H_
#define BITWISE_H_

int getNthBitFromLSB(int number, int nthBit);
void setNthBitFromLSB(int* number, int nthBit);
void clearNthBitFromLSB(int* number, int nthBit);
int countOne(int number);
void printBinary(int number, int nbitsToPrint);

#endif