#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 100

typedef struct
{
    char name[MAX_NAME_LENGTH];
} Employee;

void bubbleSort(Employee employees[], int n)
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

int main()
{
    FILE *file;
    Employee employees[MAX_EMPLOYEES];
    int n = 0;

    file = fopen("employee.txt", "r");
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return 1;
    }

    while (fscanf(file, "%s", employees[n].name) != EOF)
    {
        n++;
    }
    fclose(file);

    bubbleSort(employees, n);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", employees[i].name);
    }

    return 0;
}
