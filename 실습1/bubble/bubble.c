#include <stdio.h>
#include <stdlib.h>

#define INPUT_MAX 1024                  // Mximum number of elements
#define INPUT_FILE_NAME "input_sort.txt"     // Input file containing input data to sort (+ the number of elements)

void swapVariable(int* a, int* b); // swap 함수 선언
void bubbleSort(int dataTotal, int* dataArray); // 버블 소트 선언

// Read input data from a file and write the data into buffer
int readInput(int* buffer)
{
    FILE* fd;    
    int dataTotal;
    int i;

    fd = fopen(INPUT_FILE_NAME, "r");
	if (fd == NULL)	{
		printf("Error: Failed to open '%s'.\n", INPUT_FILE_NAME);
		return -1;
	}

	/* read input file to get task parameters */
	fscanf(fd, "%d \n", &dataTotal);
    if (dataTotal > INPUT_MAX) {
        printf("The number of elements exceeds the limit %d.\n", INPUT_MAX);
        return -1;
    }

	for (i = 0; i < dataTotal; i++) {
		fscanf(fd, "%d ", &buffer[i]);
    }

    fclose(fd);
   
    return dataTotal;
}


int main() {

    int inputBuffer[INPUT_MAX];
    int dataNum;

    dataNum = readInput(inputBuffer);

    bubbleSort(dataNum, inputBuffer);

    for (int i = 0; i < dataNum; i++) {
        printf("%d ", inputBuffer[i]);
    }

    return 0;
}

void bubbleSort(int dataTotal, int* dataArray) {

    for (int i = dataTotal - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (dataArray[j] > dataArray[j+1]) {
                swapVariable(&dataArray[j], &dataArray[j+1]);
            }
        }
    }

    return;
}

void swapVariable(int* a, int* b) {
    int tmp;

    tmp  = *a;
    *a = *b;
    *b = tmp;

    return;
}