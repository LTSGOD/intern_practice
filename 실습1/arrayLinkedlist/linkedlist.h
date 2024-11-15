#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

// Node 구조체
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** phead, int item);
int pop(Node** phead);
void print(Node* head);

#endif