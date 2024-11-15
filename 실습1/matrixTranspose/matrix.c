#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100                 // Mximum number of elements
#define INPUT_FILE_NAME "input_matrix.txt"     // Input file containing input data to sort (+ the number of elements)

void swap(int* a, int* b);
int readInput(int inputData[][MAX_SIZE], int* rowSize, int* columnSize);
void generateMatrixTranspose(int rowSize, int columnSize, int matrix[][MAX_SIZE]);

int main() {

    int buffer[MAX_SIZE][MAX_SIZE];
    int rowSize, columnSize;
    int dataNum;

    readInput(buffer, &rowSize, &columnSize);

    generateMatrixTranspose(rowSize, columnSize, buffer);

    for (int i = 0; i < columnSize; i++) {
        for (int j = 0; j < rowSize; j++) {
            printf("%d ", buffer[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void swap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void generateMatrixTranspose(int rowSize, int columnSize, int matrix[][MAX_SIZE]) {

    for (int i = 0; i < rowSize; i++) {
        for (int j = i; j <columnSize; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}

// Read input data from a file and write the data into buffer
int readInput(int inputData[][MAX_SIZE], int* rowSize, int* columnSize)
{
    FILE* fd;    
    int dataTotal;
    char tmp;

    fd = fopen(INPUT_FILE_NAME, "r");
	if (fd == NULL)	{
		printf("Error: Failed to open '%s'.\n", INPUT_FILE_NAME);
		return -1;
	}

	/* read input file to get task parameters */
	fscanf(fd, "%d \n", rowSize);
    fscanf(fd, "%c \n", &tmp);
    fscanf(fd, "%d \n", columnSize);

    dataTotal = (*rowSize) * (*columnSize);

    for (int i = 0; i < *rowSize; i++) {
        for (int j = 0; j < *columnSize; j++) {
            fscanf(fd, "%d \n", &inputData[i][j]);
        }
    }

    fclose(fd);
   
    return dataTotal;
}
