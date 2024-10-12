#include <stdio.h>
void binarysearch(int a[], int n, int key, int lb, int ub)
{
    int mid;
    mid = (lb + ub) / 2;
    if (a[mid] == key)
        printf("element found at %d \n", mid + 1);
    else if (key > a[mid])
        binarysearch(a, n, key, mid + 1, ub);
    else
        binarysearch(a, n, key, mid - 1, lb);
}
int main()
{
    int a[10], i, n, key;
    printf("Enter the Size \n");
    scanf("%d", &n);
    printf("Enter the Elements into array \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the key to search \n");
    scanf("%d", &key);
    binarysearch(a, n, key, 0, n - 1);
}
