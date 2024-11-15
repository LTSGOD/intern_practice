#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

#define INPUT_MAX 1024                  // Mximum number of elements
#define INPUT_FILE_NAME "input_linked_list_stack.txt"     // Input file containing input data to sort (+ the number of elements)

int main() {

    FILE* fd;    
    int dataTotal;
    Node* head = NULL;

    // file open
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

    // push pop ó��
    for (int i = 0; i < dataTotal; i++) {
        char command[6];
		fscanf(fd, "%s ", &command); // ��ɾ� �б�

        if (strcmp(command, "push") == 0) {
            int target;
            fscanf(fd, "%d ", &target);
            push(&head, target);
        } else {
            pop(&head);
        }
    }

    // ���ÿ� �����ִ� �� ���
    printf("Reamining elements in the stack: ");

    print(head);

    fclose(fd);

    return 0;
}
