#include <Stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function declarations
struct Node *create();
void display(struct Node *head);
void sort(struct Node *head); // Function to sort the list
