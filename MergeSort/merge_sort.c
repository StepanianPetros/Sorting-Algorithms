#include "list.h"

Node* mergeSort(Node* head);
void splitlist(Node* head, Node** firstPart, Node** secondPart);
Node* merge(Node* firstPart, Node* secondPart);

void sortList(List* li)
{
    if (li->head == NULL || li->size < 2)
        return;
    
    li->head = mergeSort(li->head);
    
    Node* cur = li->head;
    while (cur->next != NULL)
        cur = cur->next;

    li->tail = cur;
    cur->next = NULL;
}

Node* mergeSort(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node* firstPart;
    Node* secondPart;
    splitlist(head, &firstPart, &secondPart);

    firstPart = mergeSort(firstPart);
    secondPart = mergeSort(secondPart);

    return merge(firstPart, secondPart);
}

void splitlist(Node* head, Node** firstPart, Node** secondPart)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        if (fast != NULL)
            slow = slow->next;
    }

    *firstPart = head;
    *secondPart = slow->next;
    
    if (*secondPart != NULL)
        (*secondPart)->prev = NULL;

    slow->next = NULL;
}

Node* merge(Node* firstPart, Node* secondPart)
{
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (firstPart != NULL && secondPart != NULL)
    {
        if (firstPart->value < secondPart->value)
        {
            tail->next = firstPart;
            firstPart->prev = tail;
            firstPart = firstPart->next;
        }
        else
        {
            tail->next = secondPart;
            secondPart->prev = tail;
            secondPart = secondPart->next;
        }
        tail = tail->next;
    }

    if (firstPart != NULL)
    {
        tail->next = firstPart;
        firstPart->prev = tail;
    }
    else
    {
        tail->next = secondPart;
        if (secondPart != NULL)
            secondPart->prev = tail;
    }

    dummy.next->prev = NULL;
    return dummy.next;
}