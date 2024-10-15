#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

int evaluatePostfix(char *exp)
{
    StackNode *stack = NULL;
    for (int i = 0; exp[i]; ++i)
    {
        if (isdigit(exp[i]))
        {
            push(&stack, exp[i] - '0');
        }
        else
        {
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            switch (exp[i])
            {
            case '+':
                push(&stack, val2 + val1);
                break;
            case '-':
                push(&stack, val2 - val1);
                break;
            case '*':
                push(&stack, val2 * val1);
                break;
            case '/':
                push(&stack, val2 / val1);
                break;
            }
        }
    }
    return pop(&stack);
}

int main()
{
    char exp;
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    printf("Postfix evaluation: %d\n", evaluatePostfix(exp));
    return 0;
}
