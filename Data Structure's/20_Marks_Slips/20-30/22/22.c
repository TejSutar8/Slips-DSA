#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100
#define MAX_NAME_LENGTH 100

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int stdCode;
} City;

int sentinelLinearSearch(City cities[], int n, char *target)
{
    strcpy(cities[n].name, target);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(cities[i].name, target) == 0)
        {
            return cities[i].stdCode;
        }
    }

    return -1;
}

int main()
{
    FILE *file;
    City cities[MAX_CITIES];
    int count = 0;

    file = fopen("cities.txt", "r");
    if (file == NULL)
    {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    while (count < MAX_CITIES && fscanf(file, "%s %d", cities[count].name, &cities[count].stdCode) == 2)
    {
        count++;
    }

    fclose(file);

    char target[MAX_NAME_LENGTH];
    printf("Enter the name of the city: ");
    scanf("%s", target);

    int result = sentinelLinearSearch(cities, count, target);

    if (result != -1)
    {
        printf("The STD code for %s is %d.\n", target, result);
    }
    else
    {
        printf("City not in the list.\n");
    }

    return 0;
}
