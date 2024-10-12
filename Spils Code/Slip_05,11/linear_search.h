#include <stdio.h>
void linearsearch(int a[], int n, int key)
{
    int i;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("The Element is Found : \n");
            break;
        }
    }
    if (i == n)
    {
        printf("The element is not found. \n");
    }
}
