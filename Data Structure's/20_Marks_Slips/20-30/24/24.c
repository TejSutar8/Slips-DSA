#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 100

void insertionSort(char names[][MAX_NAME_LENGTH], int n)
{
    for (int i = 1; i < n; i++)
    {
        char key[MAX_NAME_LENGTH];
        strcpy(key, names[i]);
        int j = i - 1;
        while (j >= 0 && strcmp(names[j], key) > 0)
        {
            strcpy(names[j + 1], names[j]);
            j--;
        }
        strcpy(names[j + 1], key);
    }
}

int main()
{
    FILE *file;
    char names[MAX_EMPLOYEES][MAX_NAME_LENGTH];
    int count = 0;

    file = fopen("employee.txt", "r");
    if (file == NULL)
    {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    while (count < MAX_EMPLOYEES && fgets(names[count], MAX_NAME_LENGTH, file) != NULL)
    {
        names[count][strcspn(names[count], "\n")] = '\0';
        count++;
    }

    fclose(file);

    insertionSort(names, count);

    printf("Sorted employee names:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", names[i]);
    }

    return 0;
}
