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

void insertEnd(Node **head, int coeff, int exp)
{
    Node *newNode = createNode(coeff, exp);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayPolynomial(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
        {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

Node *multiplyPolynomials(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    Node *temp1 = poly1;
    Node *temp2 = poly2;

    while (temp1 != NULL)
    {
        while (temp2 != NULL)
        {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            insertEnd(&result, coeff, exp);
            temp2 = temp2->next;
        }
        temp2 = poly2;
        temp1 = temp1->next;
    }

    return result;
}

void simplifyPolynomial(Node **head)
{
    Node *ptr1 = *head;
    Node *ptr2;
    Node *dup;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        while (ptr2->next != NULL)
        {
            if (ptr1->exp == ptr2->next->exp)
            {
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;
    Node *result = NULL;

    int n, coeff, exp;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    printf("Enter terms of first polynomial (coeff exp):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &coeff, &exp);
        insertEnd(&poly1, coeff, exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    printf("Enter terms of second polynomial (coeff exp):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &coeff, &exp);
        insertEnd(&poly2, coeff, exp);
    }

    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    result = multiplyPolynomials(poly1, poly2);
    simplifyPolynomial(&result);

    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}
