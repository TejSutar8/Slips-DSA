#include <stdio.h>
#include "linear_search.h"

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
    linearsearch(a, n, key);
}
