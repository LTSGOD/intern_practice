#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// pushFirst
void push(Node** phead, int item) {

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = *phead; // 현재 헤드노드로 설정

    // 새로운 헤드
    *phead = newNode;

    return;
}

// popFirst
int pop(Node** phead) {

    if (phead == NULL) {
        return -1;
    } // 빈 스택이면

    Node* topNode = (*phead);

    int value = topNode->data;

    *phead = topNode->next; // head 갱신

    free(topNode); // 메모리 해제

    return value;
}

void print(Node* head) {

    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}