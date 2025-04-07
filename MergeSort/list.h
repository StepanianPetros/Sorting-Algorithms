#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* next;
    struct Node* prev;
    
} Node;

typedef struct List
{
    Node* head;
    Node* tail;
    int size;
} List;

void initList(List*);

void push_back(List*, int);
void push_front(List*, int);
void pop_back(List*);
void pop_front(List*);
void printList(List*);

int getSize(List*);
void sortList(List*);