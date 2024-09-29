#include <stdio.h>
#include <stdlib.h>
#include "doublylist.h"

// Function to create a doubly linked list
struct Node *create()
{
    struct Node *head = NULL;
    struct Node *temp;
    struct Node *newNode;
    int choice = 1, value;

    while (choice)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the value for the node: ");
        scanf("%d", &value);
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }

        printf("Do you want to add another node? (1/0): ");
        scanf("%d", &choice);
    }
    return head;
}

// Function to display the doubly linked list
void display(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    printf("The elements of the list are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to sort the doubly linked list using Bubble Sort
void sort(struct Node *head)
{
    if (head == NULL)
        return; // If the list is empty

    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL; // Last node

    // Perform bubble sort
    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                // Swap data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1; // Set swapped flag
            }
            ptr1 = ptr1->next; // Move to the next node
        }
        lptr = ptr1; // Update last pointer
    } while (swapped); // Repeat until no swaps are made
}

// Main function
int main()
{
    struct Node *head = NULL;
    int choice;

    do
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Sort List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create();
            break;
        case 2:
            display(head);
            break;
        case 3:
            sort(head); // Call sort function
            printf("List sorted successfully!\n");
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
