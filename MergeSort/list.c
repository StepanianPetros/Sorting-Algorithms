#include "list.h"

Node* createNode(int V)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = V;
    node->next = NULL;
    node->prev = NULL;
    return node;
}


int getSize(List* ll)
{
    return ll -> size;
}

void initList(List* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
void push_back(List* ll, int val)
{
    Node* node = createNode(val);

    if (ll->head == NULL && ll->tail == NULL)
    {
        ll->head = node;
        ll->tail = node;
    }
    else
    {
        ll->tail->next = node;
        node->prev = ll->tail;
        ll -> tail = node;
    }
    ++ll->size;
}
void push_front(List* ll, int val)
{
    Node* node = createNode(val);

    if (ll->head == NULL && ll->tail == NULL)
    {
        ll->head = node;
        ll->tail = node;
    }
    else
    {
        ll->head->prev = node;
        node->next = ll->head;
        ll->head = node;
    }
    ++ll->size;
}
void pop_back(List* ll)
{
    if (ll->head == NULL)
        return;

    if (ll->head == ll->tail) 
    {
        free(ll->head);
        ll->head = ll->tail = NULL;
    }
    else
    {
        ll->tail = ll->tail->prev;
        free(ll->tail->next);
        ll->tail->next = NULL;
    }
    --ll->size;
}
void pop_front(List* ll)
{
    if (ll->head == NULL)
        return;

    if (ll->head == ll->tail)  
    {
        free(ll->head);
        ll->head = ll->tail = NULL;
    }
    else
    {
        ll->head = ll->head->next;
        free(ll->head->prev);
        ll->head->prev = NULL;
    }
    --ll->size;
}
void printList(List* ll)
{
    Node* cur = ll->head;
    while (cur != NULL)
    {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("size is: %d", getSize(ll));
    printf("\n");
}