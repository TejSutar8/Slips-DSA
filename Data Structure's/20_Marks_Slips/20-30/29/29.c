#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node **last, int data)
{
    Node *newNode = createNode(data);
    if (*last == NULL)
    {
        *last = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        *last = newNode;
    }
}

void appendMultiple(Node **last, int n)
{
    int data;
    for (int i = 0; i < n; i++)
    {
        printf("Enter data for element %d: ", i + 1);
        scanf("%d", &data);
        append(last, data);
    }
}

void display(Node *last)
{
    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = last->next;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(back to start)\n");
}

int main()
{
    Node *last = NULL;
    int n;

    printf("Enter the number of elements to append: ");
    scanf("%d", &n);

    appendMultiple(&last, n);

    printf("Circular List: ");
    display(last);

    return 0;
}
