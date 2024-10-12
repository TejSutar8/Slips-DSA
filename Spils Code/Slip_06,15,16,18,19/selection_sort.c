#include <stdio.h>
#include "selection_sort.h"

int main()
{
    int a[] = {30, 42, 61, 7, 5};
    int n = sizeof(a) / sizeof(a[0]);
    selectionSort(a, n);
    printarray(a, n);
    return 0;
}