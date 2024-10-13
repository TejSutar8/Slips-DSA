#include <stdio.h>
#include <stdlib.h>
#include "singly.h"

int main()
{
    struct Node *head = NULL;
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    display(head);
     
}