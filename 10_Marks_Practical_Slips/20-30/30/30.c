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

void bubble_sort(Employee employees[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(employees[j].name, employees[j + 1].name) > 0)
            {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
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
        bubble_sort(employees, n);
        write_sorted_data("sortedemponname.txt", employees, n);
        printf("Data sorted by name and written to sortedemponname.txt\n");
    }
    else
    {
        printf("No data to sort.\n");
    }
    return 0;
}
