/*
 * Q107_Salary_Management.c
 * ------------------------
 * A salary management system that calculates employee salary
 * components including basic pay, HRA, DA, tax, and net salary.
 *
 * Features:
 *   - Add employees with basic salary
 *   - Auto-calculate HRA (20% of basic), DA (50% of basic)
 *   - Tax calculation based on income slabs
 *   - PF deduction (12% of basic)
 *   - Generate detailed salary slip
 *   - Display all employee salaries
 *   - Summary statistics (total payroll, average salary)
 */

#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 50
#define NAME_LEN 50
#define DEPT_LEN 30

/* HRA, DA, PF rates as percentages of basic */
#define HRA_RATE 20.0
#define DA_RATE  50.0
#define PF_RATE  12.0

/* Tax slabs (annual income) */
#define TAX_SLAB1 250000.0   /* 0% up to 2.5L */
#define TAX_SLAB2 500000.0   /* 5% for 2.5L - 5L */
#define TAX_SLAB3 1000000.0  /* 20% for 5L - 10L */
                              /* 30% above 10L */

/* Employee salary structure */
typedef struct {
    int empId;
    char name[NAME_LEN];
    char department[DEPT_LEN];
    float basicPay;
    float hra;          /* House Rent Allowance */
    float da;           /* Dearness Allowance */
    float grossSalary;
    float pf;           /* Provident Fund deduction */
    float tax;          /* Income tax deduction */
    float netSalary;
    int isActive;
} EmpSalary;

EmpSalary salaries[MAX_EMPLOYEES];
int empCount = 0;

/* Calculate annual tax based on income slab */
float calculateTax(float annualIncome) {
    float tax = 0.0;

    if (annualIncome <= TAX_SLAB1) {
        tax = 0.0;     /* No tax */
    } else if (annualIncome <= TAX_SLAB2) {
        tax = (annualIncome - TAX_SLAB1) * 0.05;
    } else if (annualIncome <= TAX_SLAB3) {
        tax = (TAX_SLAB2 - TAX_SLAB1) * 0.05 +
              (annualIncome - TAX_SLAB2) * 0.20;
    } else {
        tax = (TAX_SLAB2 - TAX_SLAB1) * 0.05 +
              (TAX_SLAB3 - TAX_SLAB2) * 0.20 +
              (annualIncome - TAX_SLAB3) * 0.30;
    }

    return tax / 12.0;  /* Return monthly tax */
}

/* Calculate salary components */
void calculateSalary(EmpSalary *e) {
    float annualGross;

    e->hra = e->basicPay * (HRA_RATE / 100.0f);
    e->da = e->basicPay * (DA_RATE / 100.0f);
    e->grossSalary = e->basicPay + e->hra + e->da;

    e->pf = e->basicPay * (PF_RATE / 100.0f);

    /* Calculate tax based on annual gross salary */
    annualGross = e->grossSalary * 12.0f;
    e->tax = calculateTax(annualGross);

    e->netSalary = e->grossSalary - e->pf - e->tax;
}

/* Find employee by ID */
int findById(int id) {
    int i;
    for (i = 0; i < empCount; i++) {
        if (salaries[i].empId == id && salaries[i].isActive)
            return i;
    }
    return -1;
}

/* Display menu */
void displayMenu(void) {
    printf("\n============================================\n");
    printf("       SALARY MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("  1. Add Employee\n");
    printf("  2. Generate Salary Slip\n");
    printf("  3. Display All Salaries\n");
    printf("  4. Update Basic Pay\n");
    printf("  5. Delete Employee\n");
    printf("  6. Payroll Summary\n");
    printf("  7. Tax Slab Information\n");
    printf("  8. Exit\n");
    printf("============================================\n");
    printf("Enter your choice: ");
}

/* Add new employee */
void addEmployee(void) {
    EmpSalary *e;
    int id;

    if (empCount >= MAX_EMPLOYEES) {
        printf("Error: Maximum employee limit reached!\n");
        return;
    }

    printf("\n--- Add Employee ---\n");
    printf("Enter Employee ID: ");
    if (scanf("%d", &id) != 1 || id <= 0) {
        printf("Error: Invalid ID!\n");
        while (getchar() != '\n');
        return;
    }

    if (findById(id) != -1) {
        printf("Error: Employee ID %d already exists!\n", id);
        return;
    }

    e = &salaries[empCount];
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

    printf("Enter Basic Pay (monthly): Rs. ");
    if (scanf("%f", &e->basicPay) != 1 || e->basicPay <= 0) {
        printf("Error: Invalid basic pay!\n");
        while (getchar() != '\n');
        return;
    }

    /* Calculate all salary components */
    calculateSalary(e);
    e->isActive = 1;
    empCount++;

    printf("\nEmployee added successfully!\n");
    printf("Net Monthly Salary: Rs. %.2f\n", e->netSalary);
}

/* Generate detailed salary slip */
void generateSalarySlip(void) {
    int id, idx;

    printf("\nEnter Employee ID: ");
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

    EmpSalary *e = &salaries[idx];

    printf("\n+====================================================+\n");
    printf("|              MONTHLY SALARY SLIP                    |\n");
    printf("+====================================================+\n");
    printf("| Employee ID   : %-33d |\n", e->empId);
    printf("| Name          : %-33s |\n", e->name);
    printf("| Department    : %-33s |\n", e->department);
    printf("+----------------------------------------------------+\n");
    printf("|               EARNINGS                              |\n");
    printf("+----------------------------------------------------+\n");
    printf("| Basic Pay         : Rs. %26.2f |\n", e->basicPay);
    printf("| HRA (%.0f%%)          : Rs. %26.2f |\n", HRA_RATE, e->hra);
    printf("| DA  (%.0f%%)          : Rs. %26.2f |\n", DA_RATE, e->da);
    printf("+----------------------------------------------------+\n");
    printf("| GROSS SALARY      : Rs. %26.2f |\n", e->grossSalary);
    printf("+----------------------------------------------------+\n");
    printf("|               DEDUCTIONS                            |\n");
    printf("+----------------------------------------------------+\n");
    printf("| PF  (%.0f%%)          : Rs. %26.2f |\n", PF_RATE, e->pf);
    printf("| Income Tax        : Rs. %26.2f |\n", e->tax);
    printf("+----------------------------------------------------+\n");
    printf("| Total Deductions  : Rs. %26.2f |\n", e->pf + e->tax);
    printf("+====================================================+\n");
    printf("| NET SALARY        : Rs. %26.2f |\n", e->netSalary);
    printf("+====================================================+\n");
    printf("| Annual CTC        : Rs. %26.2f |\n", e->grossSalary * 12.0f);
    printf("+====================================================+\n");
}

/* Display all salaries */
void displayAllSalaries(void) {
    int i, count = 0;

    printf("\n=====================================================================\n");
    printf("                       ALL EMPLOYEE SALARIES\n");
    printf("=====================================================================\n");
    printf("%-6s %-18s %-12s %-12s %-12s %-12s\n",
           "ID", "Name", "Basic", "Gross", "Deductions", "Net Salary");
    printf("------ ------------------ ------------ ------------ ------------ ------------\n");

    for (i = 0; i < empCount; i++) {
        if (salaries[i].isActive) {
            printf("%-6d %-18s %-12.2f %-12.2f %-12.2f %-12.2f\n",
                   salaries[i].empId, salaries[i].name,
                   salaries[i].basicPay, salaries[i].grossSalary,
                   salaries[i].pf + salaries[i].tax,
                   salaries[i].netSalary);
            count++;
        }
    }

    if (count == 0)
        printf("  No employee salary records found.\n");
    else
        printf("\nTotal employees: %d\n", count);
}

/* Update basic pay and recalculate */
void updateBasicPay(void) {
    int id, idx;
    float newBasic;

    printf("\nEnter Employee ID: ");
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

    printf("Current Basic Pay: Rs. %.2f\n", salaries[idx].basicPay);
    printf("Enter new Basic Pay: Rs. ");
    if (scanf("%f", &newBasic) != 1 || newBasic <= 0) {
        printf("Invalid basic pay!\n");
        while (getchar() != '\n');
        return;
    }

    salaries[idx].basicPay = newBasic;
    calculateSalary(&salaries[idx]);

    printf("Basic pay updated! New Net Salary: Rs. %.2f\n", salaries[idx].netSalary);
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

    printf("Delete '%s' (ID: %d)? (y/n): ", salaries[idx].name, id);
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        salaries[idx].isActive = 0;
        printf("Employee deleted successfully!\n");
    } else {
        printf("Deletion cancelled.\n");
    }
}

/* Payroll summary */
void payrollSummary(void) {
    int i, count = 0;
    float totalPayroll = 0, highestSalary = 0, lowestSalary = 0;
    char highestName[NAME_LEN] = "", lowestName[NAME_LEN] = "";
    int first = 1;

    for (i = 0; i < empCount; i++) {
        if (salaries[i].isActive) {
            totalPayroll += salaries[i].netSalary;
            count++;

            if (first || salaries[i].netSalary > highestSalary) {
                highestSalary = salaries[i].netSalary;
                strcpy(highestName, salaries[i].name);
            }
            if (first || salaries[i].netSalary < lowestSalary) {
                lowestSalary = salaries[i].netSalary;
                strcpy(lowestName, salaries[i].name);
            }
            first = 0;
        }
    }

    if (count == 0) {
        printf("No payroll data available.\n");
        return;
    }

    printf("\n--- Payroll Summary ---\n");
    printf("Total Employees     : %d\n", count);
    printf("Total Monthly Payroll: Rs. %.2f\n", totalPayroll);
    printf("Average Net Salary  : Rs. %.2f\n", totalPayroll / count);
    printf("Highest Salary      : Rs. %.2f (%s)\n", highestSalary, highestName);
    printf("Lowest Salary       : Rs. %.2f (%s)\n", lowestSalary, lowestName);
    printf("Annual Payroll Cost : Rs. %.2f\n", totalPayroll * 12.0f);
}

/* Display tax slab info */
void taxSlabInfo(void) {
    printf("\n--- Income Tax Slabs (Annual) ---\n");
    printf("Up to Rs. 2,50,000       : 0%% (No tax)\n");
    printf("Rs. 2,50,001 - 5,00,000  : 5%%\n");
    printf("Rs. 5,00,001 - 10,00,000 : 20%%\n");
    printf("Above Rs. 10,00,000      : 30%%\n");
    printf("\n--- Salary Components ---\n");
    printf("HRA  = %.0f%% of Basic Pay\n", HRA_RATE);
    printf("DA   = %.0f%% of Basic Pay\n", DA_RATE);
    printf("PF   = %.0f%% of Basic Pay (deducted)\n", PF_RATE);
}

int main(void) {
    int choice;

    printf("*********************************************\n");
    printf("*     SALARY MANAGEMENT SYSTEM v1.0         *\n");
    printf("*********************************************\n");

    while (1) {
        displayMenu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addEmployee();          break;
            case 2: generateSalarySlip();   break;
            case 3: displayAllSalaries();   break;
            case 4: updateBasicPay();       break;
            case 5: deleteEmployee();       break;
            case 6: payrollSummary();       break;
            case 7: taxSlabInfo();          break;
            case 8:
                printf("\nExiting Salary Management System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select 1-8.\n");
        }
    }

    return 0;
}
