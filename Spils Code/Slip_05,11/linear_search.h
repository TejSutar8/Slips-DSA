#include <stdio.h>
void linearsearch(int a[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("the element found %d", i + 1);
            break;
        }
    }
    if (i == n)
    {
        printf("element not found \n");
    }
}
