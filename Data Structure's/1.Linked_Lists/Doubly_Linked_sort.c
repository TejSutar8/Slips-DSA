
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next, *prev;
};

struct Node *create(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insert(struct Node **head, int data)
{
    struct Node *newNode = create(data), *last = *head;
    if (!(*head))
    {
        *head = newNode;
        return;
    }
    while (last->next)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

void display(struct Node *node)
{
    printf("Forward: ");
    while (node)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    display(head);
    return 0;
}