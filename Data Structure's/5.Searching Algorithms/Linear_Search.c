#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int key = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = linearSearch(arr, n, key);
    (result == -1) ? printf("Element not found\n") : printf("Element found at index %d\n", result);
    return 0;
}
