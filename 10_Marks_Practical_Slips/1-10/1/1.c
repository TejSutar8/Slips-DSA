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

void insert(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL || (*head)->data >= data)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL && current->next->data < data)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

Node *mergeLists(Node *list1, Node *list2)
{
    Node *mergedHead = NULL;
    Node *mergedTail = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        Node *temp;
        if (list1->data <= list2->data)
        {
            temp = createNode(list1->data);
            list1 = list1->next;
        }
        else
        {
            temp = createNode(list2->data);
            list2 = list2->next;
        }

        if (mergedHead == NULL)
        {
            mergedHead = mergedTail = temp;
        }
        else
        {
            mergedTail->next = temp;
            mergedTail = temp;
        }
    }

    while (list1 != NULL)
    {
        Node *temp = createNode(list1->data);
        mergedTail->next = temp;
        mergedTail = temp;
        list1 = list1->next;
    }

    while (list2 != NULL)
    {
        Node *temp = createNode(list2->data);
        mergedTail->next = temp;
        mergedTail = temp;
        list2 = list2->next;
    }

    return mergedHead;
}

void display(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *list1 = NULL;
    Node *list2 = NULL;

    insert(&list1, 5);
    insert(&list1, 3);
    insert(&list1, 1);

    insert(&list2, 6);
    insert(&list2, 4);
    insert(&list2, 2);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    Node *mergedList = mergeLists(list1, list2);
    printf("Merged List: ");
    display(mergedList);

    return 0;
}
