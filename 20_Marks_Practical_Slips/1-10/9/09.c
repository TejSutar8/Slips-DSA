#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

int readEmployeeData(Employee employees[], int max_size)
{
    FILE *file = fopen("employee.txt", "r");
    if (file == NULL)
    {
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%d %s %d %f", &employees[count].id, employees[count].name, &employees[count].age, &employees[count].salary) != EOF && count < max_size)
    {
        count++;
    }

    fclose(file);
    return count;
}

void quickSort(Employee employees[], int low, int high)
{
    if (low < high)
    {
        int pivot = employees[high].age;
        int i = (low - 1);

        for (int j = low; j < high; j++)
        {
            if (employees[j].age <= pivot)
            {
                i++;
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }

        Employee temp = employees[i + 1];
        employees[i + 1] = employees[high];
        employees[high] = temp;

        int pi = i + 1;

        quickSort(employees, low, pi - 1);
        quickSort(employees, pi + 1, high);
    }
}

void writeSortedData(Employee employees[], int count)
{
    FILE *file = fopen("sortedemponage.txt", "w");
    if (file == NULL)
    {
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d %s %d %.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
    }

    fclose(file);
}

int main()
{
    Employee employees[100];
    int count = readEmployeeData(employees, 100);

    quickSort(employees, 0, count - 1);

    writeSortedData(employees, count);

    return 0;
}
