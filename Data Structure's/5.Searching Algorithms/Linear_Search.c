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
