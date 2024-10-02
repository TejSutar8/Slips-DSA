#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    struct Stack src, dest;
    initialize(&src);
    initialize(&dest);

    int choice, value;

    while (1)
    {
        printf("\n1. Push to source stack\n2.Copy to destination stack\n3. Display source stack\n4. Display destination stack\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(&src, value);
            break;
        case 2:
            copyStack(&src, &dest);
            printf("Stack copied successfully.\n");
            break;
        case 3:
            printf("Source Stack: ");
            display(&src);
            break;
        case 4:
            printf("Destination Stack: ");
            display(&dest);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}