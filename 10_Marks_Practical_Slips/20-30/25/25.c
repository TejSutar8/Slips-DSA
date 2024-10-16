#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LEN 50
#define MAX_AGE 100

typedef struct {
    int emp_id;
    char name[MAX_NAME_LEN];
    int age;
} Employee;

int read_employee_data(const char *filename, Employee employees[]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open %s\n", filename);
        return -1;
    }
    int i = 0;
    while (fscanf(file, "%d,%[^,],%d\n", 
                  &employees[i].emp_id, 
                  employees[i].name, 
                  &employees[i].age) == 3) {
        i++;
    }
    fclose(file);
    return i;
}

void count_sort(Employee employees[], int n) {
    int count[MAX_AGE + 1] = {0};
    Employee output[MAX_EMPLOYEES];

    for (int i = 0; i < n; i++) {
        count[employees[i].age]++;
    }
    for (int i = 1; i <= MAX_AGE; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        output[count[employees[i].age] - 1] = employees[i];
        count[employees[i].age]--;
    }
    for (int i = 0; i < n; i++) {
        employees[i] = output[i];
    }
}

void write_sorted_data(const char *filename, Employee employees[], int n) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open %s\n", filename);
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d,%s,%d\n", employees[i].emp_id, employees[i].name, employees[i].age);
    }
    fclose(file);
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    int n = read_employee_data("employee.txt", employees);
    if (n > 0) {
        count_sort(employees, n);
        write_sorted_data("sortedemponage.txt", employees, n);
        printf("Data sorted by age and written to sortedemponage.txt\n");
    } else {
        printf("No data to sort.\n");
    }
    return 0;
}
