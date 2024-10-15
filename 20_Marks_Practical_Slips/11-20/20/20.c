#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *last;
} CircularList;

void initList(CircularList *list)
{
    list->last = NULL;
}

void append(CircularList *list, int n, int random)
{
    Node *newNode;
    int data;
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        if (random)
        {
            data = rand() % 100; // Random number between 0 and 99
        }
        else
        {
            printf("Enter data for element %d: ", i + 1);
            scanf("%d", &data);
        }

        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;

        if (list->last == NULL)
        {
            newNode->next = newNode;
            list->last = newNode;
        }
        else
        {
            newNode->next = list->last->next;
            list->last->next = newNode;
            list->last = newNode;
        }
    }
}

void displayList(CircularList *list)
{
    if (list->last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = list->last->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != list->last->next);
    printf("\n");
}

int main()
{
    CircularList list;
    initList(&list);
    int choice, n, random;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Append Elements\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number of elements to append: ");
            scanf("%d", &n);
            printf("Enter 1 for random data, 0 for user input: ");
            scanf("%d", &random);
            append(&list, n, random);
            break;
        case 2:
            displayList(&list);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
