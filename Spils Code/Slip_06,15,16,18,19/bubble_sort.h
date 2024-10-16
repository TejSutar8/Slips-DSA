#include <stdio.h>

void bubblesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d->", a[i]);
    printf("NULL \n");
}