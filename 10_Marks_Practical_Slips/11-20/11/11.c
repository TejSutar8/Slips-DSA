#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sentinelLinearSearch(int arr[], int n, int x)
{
    int last = arr[n - 1];
    arr[n - 1] = x;
    int i = 0;
    while (arr[i] != x)
    {
        i++;
    }
    arr[n - 1] = last;
    if (i < n - 1 || arr[n - 1] == x)
    {
        return i;
    }
    return -1;
}

int main()
{
    int n, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search: ");
    scanf("%d", &x);

    int position = sentinelLinearSearch(arr, n, x);
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
