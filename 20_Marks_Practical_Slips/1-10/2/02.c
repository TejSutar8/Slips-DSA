#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

StackNode *createStackNode(int data)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(StackNode *root)
{
    return !root;
}

void push(StackNode **root, int data)
{
    StackNode *newNode = createStackNode(data);
    newNode->next = *root;
    *root = newNode;
}

int pop(StackNode **root)
{
    if (isEmpty(*root))
        return -1;
    StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(StackNode *root)
{
    if (isEmpty(root))
        return -1;
    return root->data;
}

void displayStack(StackNode *root)
{
    StackNode *temp = root;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void copyStack(StackNode **source, StackNode **destination)
{
    StackNode *tempStack = NULL;

    while (!isEmpty(*source))
    {
        push(&tempStack, pop(source));
    }

    while (!isEmpty(tempStack))
    {
        int data = pop(&tempStack);
        push(source, data);
        push(destination, data);
    }
}

int main()
{
    StackNode *sourceStack = NULL;
    StackNode *destinationStack = NULL;
    int choice, data;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push to Source Stack\n");
        printf("2. Display Source Stack\n");
        printf("3. Copy Source Stack to Destination Stack\n");
        printf("4. Display Destination Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            push(&sourceStack, data);
            break;
        case 2:
            printf("Source Stack: ");
            displayStack(sourceStack);
            break;
        case 3:
            copyStack(&sourceStack, &destinationStack);
            printf("Stack copied.\n");
            break;
        case 4:
            printf("Destination Stack: ");
            displayStack(destinationStack);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
