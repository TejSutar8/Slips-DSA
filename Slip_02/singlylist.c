#include <stdio.h>
#include "singlylist.h"

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert into the list\n2. Display the list\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insert(&head, value);
            break;
        case 2:
            display(head);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
