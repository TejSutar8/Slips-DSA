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

int binarySearch(City cities[], int n, char *target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        int cmp = strcmp(cities[mid].name, target);
        if (cmp == 0)
        {
            return cities[mid].stdCode;
        }
        else if (cmp < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    FILE *file;
    City cities[MAX_CITIES];
    int count = 0;

    file = fopen("sortedcities.txt", "r");
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

    int result = binarySearch(cities, count, target);

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
