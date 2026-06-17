/*
 * Q106_Employee_Management.c
 * --------------------------
 * An employee management system using structures for managing
 * employee records with a menu-driven interface.
 *
 * Features:
 *   - Add new employees with unique ID
 *   - Display all employees in tabular format
 *   - Search by ID or name
 *   - Update employee details
 *   - Delete employee records
 *   - Sort by ID or salary
 *   - Department-wise summary
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMPLOYEES 100
#define NAME_LEN 50
#define DEPT_LEN 30
#define DESIG_LEN 30

/* Employee structure */
typedef struct {
    int empId;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    char designation[DESIG_LEN];
    float salary;
    int isActive;
} Employee;

Employee employees[MAX_EMPLOYEES];
int empCount = 0;

/* Find employee by ID, return index or -1 */
int findById(int id) {
    int i;
    for (i = 0; i < empCount; i++) {
        if (employees[i].empId == id && employees[i].isActive)
            return i;
    }
    return -1;
}

/* Display the menu */
void displayMenu(void) {
    printf("\n============================================\n");
    printf("      EMPLOYEE MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("  1. Add Employee\n");
    printf("  2. Display All Employees\n");
    printf("  3. Search Employee by ID\n");
    printf("  4. Search Employee by Name\n");
    printf("  5. Update Employee\n");
    printf("  6. Delete Employee\n");
    printf("  7. Sort by Salary\n");
    printf("  8. Department Summary\n");
    printf("  9. Exit\n");
    printf("============================================\n");
    printf("Enter your choice: ");
}

/* Add a new employee */
void addEmployee(void) {
    Employee *e;
    int id;

    if (empCount >= MAX_EMPLOYEES) {
        printf("Error: Maximum employee limit reached!\n");
        return;
    }

    printf("\n--- Add New Employee ---\n");
    printf("Enter Employee ID: ");
    if (scanf("%d", &id) != 1 || id <= 0) {
        printf("Error: Invalid Employee ID!\n");
        while (getchar() != '\n');
        return;
    }

    if (findById(id) != -1) {
        printf("Error: Employee ID %d already exists!\n", id);
        return;
    }

    e = &employees[empCount];
    e->empId = id;

    printf("Enter Name: ");
    getchar();
    fgets(e->name, NAME_LEN, stdin);
    e->name[strcspn(e->name, "\n")] = '\0';

    if (strlen(e->name) == 0) {
        printf("Error: Name cannot be empty!\n");
        return;
    }

    printf("Enter Department: ");
    fgets(e->department, DEPT_LEN, stdin);
    e->department[strcspn(e->department, "\n")] = '\0';

    printf("Enter Designation: ");
    fgets(e->designation, DESIG_LEN, stdin);
    e->designation[strcspn(e->designation, "\n")] = '\0';

    printf("Enter Salary: ");
    if (scanf("%f", &e->salary) != 1 || e->salary < 0) {
        printf("Error: Invalid salary!\n");
        while (getchar() != '\n');
        return;
    }

    e->isActive = 1;
    empCount++;
    printf("\nEmployee added successfully! (Total: %d)\n", empCount);
}

/* Display all employees */
void displayAll(void) {
    int i, count = 0;

    printf("\n==========================================================================\n");
    printf("                        ALL EMPLOYEE RECORDS\n");
    printf("==========================================================================\n");
    printf("%-6s %-18s %-14s %-14s %-10s\n",
           "ID", "Name", "Department", "Designation", "Salary");
    printf("------ ------------------ -------------- -------------- ----------\n");

    for (i = 0; i < empCount; i++) {
        if (employees[i].isActive) {
            printf("%-6d %-18s %-14s %-14s %.2f\n",
                   employees[i].empId, employees[i].name,
                   employees[i].department, employees[i].designation,
                   employees[i].salary);
            count++;
        }
    }

    if (count == 0) {
        printf("  No employee records found.\n");
    } else {
        printf("\nTotal active employees: %d\n", count);
    }
}

/* Search by ID */
void searchById(void) {
    int id, idx;

    printf("\nEnter Employee ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    idx = findById(id);
    if (idx == -1) {
        printf("Employee with ID %d not found!\n", id);
        return;
    }

    printf("\n--- Employee Found ---\n");
    printf("Employee ID  : %d\n", employees[idx].empId);
    printf("Name         : %s\n", employees[idx].name);
    printf("Department   : %s\n", employees[idx].department);
    printf("Designation  : %s\n", employees[idx].designation);
    printf("Salary       : %.2f\n", employees[idx].salary);
}

/* Search by name (partial, case-insensitive) */
void searchByName(void) {
    char searchName[NAME_LEN];
    int i, found = 0;

    printf("\nEnter name to search: ");
    getchar();
    fgets(searchName, NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    printf("\nSearch Results for \"%s\":\n", searchName);

    for (i = 0; i < empCount; i++) {
        if (employees[i].isActive) {
            char nameLower[NAME_LEN], searchLower[NAME_LEN];
            int j;

            strcpy(nameLower, employees[i].name);
            strcpy(searchLower, searchName);
            for (j = 0; nameLower[j]; j++) nameLower[j] = tolower(nameLower[j]);
            for (j = 0; searchLower[j]; j++) searchLower[j] = tolower(searchLower[j]);

            if (strstr(nameLower, searchLower) != NULL) {
                printf("  ID: %d | Name: %s | Dept: %s | Salary: %.2f\n",
                       employees[i].empId, employees[i].name,
                       employees[i].department, employees[i].salary);
                found++;
            }
        }
    }

    if (found == 0) printf("  No employees found.\n");
    else printf("\n%d employee(s) found.\n", found);
}

/* Update employee */
void updateEmployee(void) {
    int id, idx, choice;

    printf("\nEnter Employee ID to update: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    idx = findById(id);
    if (idx == -1) {
        printf("Employee with ID %d not found!\n", id);
        return;
    }

    printf("\nCurrent Details:\n");
    printf("1. Name        : %s\n", employees[idx].name);
    printf("2. Department  : %s\n", employees[idx].department);
    printf("3. Designation : %s\n", employees[idx].designation);
    printf("4. Salary      : %.2f\n", employees[idx].salary);
    printf("5. Update All\n");
    printf("What to update? (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter new Name: ");
            getchar();
            fgets(employees[idx].name, NAME_LEN, stdin);
            employees[idx].name[strcspn(employees[idx].name, "\n")] = '\0';
            break;
        case 2:
            printf("Enter new Department: ");
            getchar();
            fgets(employees[idx].department, DEPT_LEN, stdin);
            employees[idx].department[strcspn(employees[idx].department, "\n")] = '\0';
            break;
        case 3:
            printf("Enter new Designation: ");
            getchar();
            fgets(employees[idx].designation, DESIG_LEN, stdin);
            employees[idx].designation[strcspn(employees[idx].designation, "\n")] = '\0';
            break;
        case 4:
            printf("Enter new Salary: ");
            if (scanf("%f", &employees[idx].salary) != 1 || employees[idx].salary < 0) {
                printf("Invalid salary!\n");
                while (getchar() != '\n');
            }
            break;
        case 5:
            printf("Enter new Name: ");
            getchar();
            fgets(employees[idx].name, NAME_LEN, stdin);
            employees[idx].name[strcspn(employees[idx].name, "\n")] = '\0';
            printf("Enter new Department: ");
            fgets(employees[idx].department, DEPT_LEN, stdin);
            employees[idx].department[strcspn(employees[idx].department, "\n")] = '\0';
            printf("Enter new Designation: ");
            fgets(employees[idx].designation, DESIG_LEN, stdin);
            employees[idx].designation[strcspn(employees[idx].designation, "\n")] = '\0';
            printf("Enter new Salary: ");
            if (scanf("%f", &employees[idx].salary) != 1 || employees[idx].salary < 0) {
                printf("Invalid salary!\n");
                while (getchar() != '\n');
            }
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }
    printf("Employee record updated successfully!\n");
}

/* Delete employee */
void deleteEmployee(void) {
    int id, idx;
    char confirm;

    printf("\nEnter Employee ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    idx = findById(id);
    if (idx == -1) {
        printf("Employee with ID %d not found!\n", id);
        return;
    }

    printf("Delete '%s' (ID: %d)? (y/n): ", employees[idx].name, id);
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        employees[idx].isActive = 0;
        printf("Employee deleted successfully!\n");
    } else {
        printf("Deletion cancelled.\n");
    }
}

/* Sort by salary (descending) */
void sortBySalary(void) {
    int i, j;
    Employee temp;

    if (empCount < 2) {
        printf("Not enough employees to sort.\n");
        return;
    }

    for (i = 0; i < empCount - 1; i++) {
        for (j = 0; j < empCount - i - 1; j++) {
            if (employees[j].salary < employees[j + 1].salary) {
                temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }

    printf("Employees sorted by salary (highest first)!\n");
    displayAll();
}

/* Department summary */
void departmentSummary(void) {
    /* Track unique departments and their stats */
    char depts[MAX_EMPLOYEES][DEPT_LEN];
    int deptCount[MAX_EMPLOYEES];
    float deptTotal[MAX_EMPLOYEES];
    int numDepts = 0;
    int i, j, found;

    for (i = 0; i < empCount; i++) {
        if (!employees[i].isActive) continue;

        found = 0;
        for (j = 0; j < numDepts; j++) {
            if (strcmp(depts[j], employees[i].department) == 0) {
                deptCount[j]++;
                deptTotal[j] += employees[i].salary;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(depts[numDepts], employees[i].department);
            deptCount[numDepts] = 1;
            deptTotal[numDepts] = employees[i].salary;
            numDepts++;
        }
    }

    if (numDepts == 0) {
        printf("No department data available.\n");
        return;
    }

    printf("\n--- Department Summary ---\n");
    printf("%-20s %-10s %-15s %-15s\n", "Department", "Employees", "Total Salary", "Avg Salary");
    printf("-------------------- ---------- --------------- ---------------\n");

    for (i = 0; i < numDepts; i++) {
        printf("%-20s %-10d %-15.2f %-15.2f\n",
               depts[i], deptCount[i], deptTotal[i], deptTotal[i] / deptCount[i]);
    }
}

int main(void) {
    int choice;

    printf("*********************************************\n");
    printf("*    EMPLOYEE MANAGEMENT SYSTEM v1.0        *\n");
    printf("*********************************************\n");

    while (1) {
        displayMenu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addEmployee();      break;
            case 2: displayAll();       break;
            case 3: searchById();       break;
            case 4: searchByName();     break;
            case 5: updateEmployee();   break;
            case 6: deleteEmployee();   break;
            case 7: sortBySalary();     break;
            case 8: departmentSummary(); break;
            case 9:
                printf("\nExiting Employee Management System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select 1-9.\n");
        }
    }

    return 0;
}
