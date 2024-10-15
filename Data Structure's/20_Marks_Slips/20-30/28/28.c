#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 100

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int age;
} Employee;

void quickSort(Employee employees[], int low, int high)
{
    if (low < high)
    {
        int pivot = employees[high].age;
        int i = low - 1;

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

int main()
{
    FILE *inputFile, *outputFile;
    Employee employees[MAX_EMPLOYEES];
    int count = 0;

    inputFile = fopen("employee.txt", "r");
    if (inputFile == NULL)
    {
        perror("Unable to open input file");
        return EXIT_FAILURE;
    }

    while (count < MAX_EMPLOYEES && fscanf(inputFile, "%s %d", employees[count].name, &employees[count].age) == 2)
    {
        count++;
    }

    fclose(inputFile);

    quickSort(employees, 0, count - 1);

    outputFile = fopen("sortedemponage.txt", "w");
    if (outputFile == NULL)
    {
        perror("Unable to open output file");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(outputFile, "%s %d\n", employees[i].name, employees[i].age);
    }

    fclose(outputFile);

    printf("Data sorted by age and written to 'sortedemponage.txt'.\n");

    return 0;
}
