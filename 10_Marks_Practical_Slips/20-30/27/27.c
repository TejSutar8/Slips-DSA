#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LEN 50

typedef struct
{
    int emp_id;
    char name[MAX_NAME_LEN];
    int age;
} Employee;

int read_employee_data(const char *filename, Employee employees[])
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Error: Could not open %s\n", filename);
        return -1;
    }
    int i = 0;
    while (fscanf(file, "%d,%[^,],%d\n",
                  &employees[i].emp_id,
                  employees[i].name,
                  &employees[i].age) == 3)
    {
        i++;
    }
    fclose(file);
    return i;
}

void merge(Employee arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (strcmp(L[i].name, R[j].name) <= 0)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(Employee arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void write_sorted_data(const char *filename, Employee employees[], int n)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("Error: Could not open %s\n", filename);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d,%s,%d\n", employees[i].emp_id, employees[i].name, employees[i].age);
    }
    fclose(file);
}

int main()
{
    Employee employees[MAX_EMPLOYEES];
    int n = read_employee_data("employee.txt", employees);

    if (n > 0)
    {
        merge_sort(employees, 0, n - 1);
        write_sorted_data("sortedemponname.txt", employees, n);
        printf("Data sorted by name and written to sortedemponname.txt\n");
    }
    else
    {
        printf("No data to sort.\n");
    }
    return 0;
}
