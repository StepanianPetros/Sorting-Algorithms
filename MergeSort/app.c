#include "list.h"

int main()
{
    List ll;
    initList(&ll);

    push_back(&ll,  1);
    push_back(&ll,  2);
    push_back(&ll,  3);
    push_back(&ll,  7);
    push_back(&ll,  4);

    printList(&ll);

    sortList(&ll);

    printList(&ll);

    push_front(&ll, 6);
    push_front(&ll, 5);
    push_front(&ll, 8);
    push_front(&ll, 10);
    push_front(&ll, 9);

    printList(&ll);
    sortList(&ll);
    printList(&ll);

    pop_back(&ll);
    pop_back(&ll);
    pop_back(&ll);

    printList(&ll);

    pop_front(&ll);
    pop_front(&ll);
    pop_front(&ll);

    printList(&ll);

    sortList(&ll);

    printList(&ll);

    return 0;
}