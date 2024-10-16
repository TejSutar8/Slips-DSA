#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100
#define MAX_NAME_LENGTH 50

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char std_code;
} City;

int linearSearch(City cities[], int n, char target[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(cities[i].name, target) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    FILE *file = fopen("cities.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    City cities[MAX_CITIES];
    int count = 0;

    while (fscanf(file, "%s %s", cities[count].name, cities[count].std_code) != EOF)
    {
        count++;
    }
    fclose(file);

    char target[MAX_NAME_LENGTH];
    printf("Enter the name of the city: ");
    scanf("%s", target);

    int index = linearSearch(cities, count, target);
    if (index != -1)
    {
        printf("STD code for %s is %s\n", cities[index].name, cities[index].std_code);
    }
    else
    {
        printf("City not in the list\n");
    }

    return 0;
}
