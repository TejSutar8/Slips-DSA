#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} Node;

Node *createNode(int coeff, int exp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **head, int coeff, int exp)
{
    Node *newNode = createNode(coeff, exp);
    if (*head == NULL || (*head)->exp < exp)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL && current->next->exp >= exp)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

Node *addPolynomials(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    Node *p1 = poly1;
    Node *p2 = poly2;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->exp > p2->exp)
        {
            insert(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            insert(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else
        {
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0)
            {
                insert(&result, sumCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        insert(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        insert(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

void display(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%dx^%d", current->coeff, current->exp);
        if (current->next != NULL)
        {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;

    insert(&poly1, 3, 3);
    insert(&poly1, 2, 2);
    insert(&poly1, 1, 0);

    insert(&poly2, 4, 3);
    insert(&poly2, 3, 1);
    insert(&poly2, 2, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    Node *result = addPolynomials(poly1, poly2);
    printf("Sum: ");
    display(result);

    return 0;
}
