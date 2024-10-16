#include <stdio.h>
#include "bubble_sort.h"
int main()
{
    int a[] = {12, 34, 54, 32, 32};
    int n = sizeof(a) / sizeof(a[0]);
    bubblesort(a, n);
    printarray(a, n);
    return 0;
}