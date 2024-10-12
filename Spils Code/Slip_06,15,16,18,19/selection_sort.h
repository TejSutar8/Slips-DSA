#include <stdio.h>

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mid = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[mid])
                mid = j;

        int temp = a[mid];
        a[mid] = a[i];
        a[i] = temp;
    }
}

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}