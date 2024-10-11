#include <stdio.h>
#include <stdlib.h>
#include "doublylist.h"

// Function to create a doubly linked list
struct Node *create()
{
    struct Node *head = NULL; // Head of the list
    struct Node *temp;        // Temporary pointer for traversing
    struct Node *newNode;     // Pointer for new nodes
    int choice = 1, value;    // Variables for user input

    // Loop to create nodes
    while (choice)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for a new node
        printf("Enter the value for the node: ");
        scanf("%d", &value);
        newNode->data = value; // Set node data
        newNode->prev = NULL;  // Initialize previous pointer
        newNode->next = NULL;  // Initialize next pointer

        // Insert node into the list
        if (head == NULL)
        {
            head = newNode; // First node becomes head
            temp = head;    // Set temp to head
        }
        else
        {
            temp->next = newNode; // Link previous node to new node
            newNode->prev = temp; // Link new node to previous node
            temp = newNode;       // Move temp to new node
        }

        // Prompt user to add another node
        printf("Do you want to add another node? (1/0): ");
        scanf("%d", &choice);
    }
    return head; // Return head of the list
}

// Function to display the doubly linked list
void display(struct Node *head)
{
    struct Node *temp = head; // Temporary pointer for traversing
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    printf("The elements of the list are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data); // Print node data
        temp = temp->next;         // Move to next node
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL; // Pointer to the head of the list
    int choice;               // User's menu choice

    // Menu loop
    do
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create(); // Call create function
            break;
        case 2:
            display(head); // Call display function
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0); // Repeat until user chooses to exit

    return 0; // Exit program
}
