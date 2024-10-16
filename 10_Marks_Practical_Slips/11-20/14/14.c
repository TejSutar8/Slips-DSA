#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100; 
    }

    printf("Generated array: ");
    printArray(arr, n);

    printf("Enter the value to search: ");
    scanf("%d", &x);

    int position = linearSearch(arr, n, x);
    if (position != -1)
    {
        printf("Element %d found at position %d\n", x, position);
    }
    else
    {
        printf("Element %d not found in the array\n", x);
    }

    return 0;
}
