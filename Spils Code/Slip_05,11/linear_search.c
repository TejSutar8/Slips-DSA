#include <stdio.h>
#include "linear_search.h"

int main()
{
    int a[10], i, n, key;
    printf("Enter The size : ");
    scanf("%d", &n);
    printf("Enter elements : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a[i]);
    }
    printf("Enter the Key : ");
    scanf("%d", &key);
    linearsearch(a, n, key);
    return 0;
}