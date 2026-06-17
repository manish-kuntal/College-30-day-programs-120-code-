#include <stdio.h>
#include <string.h>

#define MAX_EMP 50

typedef struct {
    int id;
    char name[100];
    float salary;
} Employee;

int main() {
    Employee emps[MAX_EMP];
    int n = 0, choice;

    while (1) {
        printf("\nMini Employee System\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (n < MAX_EMP) {
                    printf("Enter ID: ");
                    scanf("%d", &emps[n].id);
                    printf("Enter Name: ");
                    scanf(" %[^\n]", emps[n].name);
                    printf("Enter Salary: ");
                    scanf("%f", &emps[n].salary);
                    n++;
                    printf("Added successfully!\n");
                } else {
                    printf("System full!\n");
                }
                break;
            case 2:
                printf("\n--- Employees ---\n");
                for (int i = 0; i < n; i++) {
                    printf("ID: %d | Name: %s | Salary: %.2f\n", emps[i].id, emps[i].name, emps[i].salary);
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
