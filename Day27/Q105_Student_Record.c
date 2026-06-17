/*
 * Q105_Student_Record.c
 * ---------------------
 * A student record management system using structures.
 * Supports CRUD operations with a menu-driven interface.
 *
 * Features:
 *   - Add new student records
 *   - Display all students
 *   - Search by roll number or name
 *   - Delete student by roll number
 *   - Update student details
 *   - Sort students by roll number
 *   - Input validation and duplicate checking
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define COURSE_LEN 30

/* Structure for student record */
typedef struct {
    int rollNo;
    char name[NAME_LEN];
    char course[COURSE_LEN];
    float marks;
    int isActive;       /* 1 = active, 0 = deleted */
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

/* Display menu */
void displayMenu(void) {
    printf("\n============================================\n");
    printf("     STUDENT RECORD MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("  1. Add Student\n");
    printf("  2. Display All Students\n");
    printf("  3. Search Student by Roll No\n");
    printf("  4. Search Student by Name\n");
    printf("  5. Update Student\n");
    printf("  6. Delete Student\n");
    printf("  7. Sort Students by Roll No\n");
    printf("  8. Show Statistics\n");
    printf("  9. Exit\n");
    printf("============================================\n");
    printf("Enter your choice: ");
}

/* Check if roll number already exists */
int findByRollNo(int rollNo) {
    int i;
    for (i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo && students[i].isActive) {
            return i;
        }
    }
    return -1;
}

/* Add a new student */
void addStudent(void) {
    Student *s;
    int rollNo;

    if (studentCount >= MAX_STUDENTS) {
        printf("Error: Maximum student limit (%d) reached!\n", MAX_STUDENTS);
        return;
    }

    printf("\n--- Add New Student ---\n");
    printf("Enter Roll Number: ");
    if (scanf("%d", &rollNo) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    /* Check for duplicates */
    if (rollNo <= 0) {
        printf("Error: Roll number must be positive!\n");
        return;
    }
    if (findByRollNo(rollNo) != -1) {
        printf("Error: Roll number %d already exists!\n", rollNo);
        return;
    }

    s = &students[studentCount];
    s->rollNo = rollNo;

    printf("Enter Name: ");
    getchar(); /* Clear newline */
    fgets(s->name, NAME_LEN, stdin);
    s->name[strcspn(s->name, "\n")] = '\0';

    if (strlen(s->name) == 0) {
        printf("Error: Name cannot be empty!\n");
        return;
    }

    printf("Enter Course: ");
    fgets(s->course, COURSE_LEN, stdin);
    s->course[strcspn(s->course, "\n")] = '\0';

    printf("Enter Marks (0-100): ");
    if (scanf("%f", &s->marks) != 1 || s->marks < 0 || s->marks > 100) {
        printf("Error: Invalid marks! Must be between 0 and 100.\n");
        while (getchar() != '\n');
        return;
    }

    s->isActive = 1;
    studentCount++;

    printf("\nStudent added successfully! (Total: %d)\n", studentCount);
}

/* Display all active students */
void displayAll(void) {
    int i, count = 0;

    printf("\n============================================\n");
    printf("          ALL STUDENT RECORDS\n");
    printf("============================================\n");

    printf("%-8s %-20s %-15s %-8s %-6s\n",
           "Roll No", "Name", "Course", "Marks", "Grade");
    printf("-------- -------------------- --------------- -------- ------\n");

    for (i = 0; i < studentCount; i++) {
        if (students[i].isActive) {
            char grade;
            if (students[i].marks >= 90) grade = 'A';
            else if (students[i].marks >= 80) grade = 'B';
            else if (students[i].marks >= 70) grade = 'C';
            else if (students[i].marks >= 60) grade = 'D';
            else if (students[i].marks >= 40) grade = 'E';
            else grade = 'F';

            printf("%-8d %-20s %-15s %-8.2f %c\n",
                   students[i].rollNo, students[i].name,
                   students[i].course, students[i].marks, grade);
            count++;
        }
    }

    if (count == 0) {
        printf("  No student records found.\n");
    } else {
        printf("\nTotal active students: %d\n", count);
    }
}

/* Search by roll number */
void searchByRollNo(void) {
    int rollNo, idx;

    printf("\nEnter Roll Number to search: ");
    if (scanf("%d", &rollNo) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    idx = findByRollNo(rollNo);
    if (idx == -1) {
        printf("Student with Roll No %d not found!\n", rollNo);
        return;
    }

    printf("\n--- Student Found ---\n");
    printf("Roll No : %d\n", students[idx].rollNo);
    printf("Name    : %s\n", students[idx].name);
    printf("Course  : %s\n", students[idx].course);
    printf("Marks   : %.2f\n", students[idx].marks);
}

/* Search by name (partial match, case-insensitive) */
void searchByName(void) {
    char searchName[NAME_LEN];
    int i, found = 0;

    printf("\nEnter name to search: ");
    getchar();
    fgets(searchName, NAME_LEN, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    /* Convert search term to lowercase for comparison */
    printf("\nSearch Results for \"%s\":\n", searchName);
    printf("%-8s %-20s %-15s %-8s\n", "Roll No", "Name", "Course", "Marks");
    printf("-------- -------------------- --------------- --------\n");

    for (i = 0; i < studentCount; i++) {
        if (students[i].isActive) {
            /* Case-insensitive partial name match */
            char nameLower[NAME_LEN], searchLower[NAME_LEN];
            int j;

            strcpy(nameLower, students[i].name);
            strcpy(searchLower, searchName);

            for (j = 0; nameLower[j]; j++) nameLower[j] = tolower(nameLower[j]);
            for (j = 0; searchLower[j]; j++) searchLower[j] = tolower(searchLower[j]);

            if (strstr(nameLower, searchLower) != NULL) {
                printf("%-8d %-20s %-15s %-8.2f\n",
                       students[i].rollNo, students[i].name,
                       students[i].course, students[i].marks);
                found++;
            }
        }
    }

    if (found == 0) {
        printf("  No students found matching \"%s\".\n", searchName);
    } else {
        printf("\n%d student(s) found.\n", found);
    }
}

/* Update student details */
void updateStudent(void) {
    int rollNo, idx, choice;

    printf("\nEnter Roll Number to update: ");
    if (scanf("%d", &rollNo) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    idx = findByRollNo(rollNo);
    if (idx == -1) {
        printf("Student with Roll No %d not found!\n", rollNo);
        return;
    }

    printf("\nCurrent details:\n");
    printf("1. Name   : %s\n", students[idx].name);
    printf("2. Course : %s\n", students[idx].course);
    printf("3. Marks  : %.2f\n", students[idx].marks);
    printf("4. Update All\n");
    printf("What to update? (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter new Name: ");
            getchar();
            fgets(students[idx].name, NAME_LEN, stdin);
            students[idx].name[strcspn(students[idx].name, "\n")] = '\0';
            break;
        case 2:
            printf("Enter new Course: ");
            getchar();
            fgets(students[idx].course, COURSE_LEN, stdin);
            students[idx].course[strcspn(students[idx].course, "\n")] = '\0';
            break;
        case 3:
            printf("Enter new Marks (0-100): ");
            if (scanf("%f", &students[idx].marks) != 1 ||
                students[idx].marks < 0 || students[idx].marks > 100) {
                printf("Invalid marks!\n");
                while (getchar() != '\n');
                return;
            }
            break;
        case 4:
            printf("Enter new Name: ");
            getchar();
            fgets(students[idx].name, NAME_LEN, stdin);
            students[idx].name[strcspn(students[idx].name, "\n")] = '\0';
            printf("Enter new Course: ");
            fgets(students[idx].course, COURSE_LEN, stdin);
            students[idx].course[strcspn(students[idx].course, "\n")] = '\0';
            printf("Enter new Marks (0-100): ");
            if (scanf("%f", &students[idx].marks) != 1 ||
                students[idx].marks < 0 || students[idx].marks > 100) {
                printf("Invalid marks!\n");
                while (getchar() != '\n');
                return;
            }
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }
    printf("Student record updated successfully!\n");
}

/* Delete student */
void deleteStudent(void) {
    int rollNo, idx;
    char confirm;

    printf("\nEnter Roll Number to delete: ");
    if (scanf("%d", &rollNo) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    idx = findByRollNo(rollNo);
    if (idx == -1) {
        printf("Student with Roll No %d not found!\n", rollNo);
        return;
    }

    printf("Are you sure you want to delete '%s' (Roll No: %d)? (y/n): ",
           students[idx].name, rollNo);
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        students[idx].isActive = 0;
        printf("Student deleted successfully!\n");
    } else {
        printf("Deletion cancelled.\n");
    }
}

/* Sort students by roll number (bubble sort) */
void sortByRollNo(void) {
    int i, j;
    Student temp;

    if (studentCount < 2) {
        printf("Not enough students to sort.\n");
        return;
    }

    for (i = 0; i < studentCount - 1; i++) {
        for (j = 0; j < studentCount - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by Roll Number!\n");
    displayAll();
}

/* Show statistics */
void showStatistics(void) {
    int i, count = 0;
    float total = 0, highest = 0, lowest = 100;
    char topperName[NAME_LEN] = "";

    for (i = 0; i < studentCount; i++) {
        if (students[i].isActive) {
            total += students[i].marks;
            count++;
            if (students[i].marks > highest) {
                highest = students[i].marks;
                strcpy(topperName, students[i].name);
            }
            if (students[i].marks < lowest) {
                lowest = students[i].marks;
            }
        }
    }

    if (count == 0) {
        printf("No student records available for statistics.\n");
        return;
    }

    printf("\n--- Class Statistics ---\n");
    printf("Total Students  : %d\n", count);
    printf("Average Marks   : %.2f\n", total / count);
    printf("Highest Marks   : %.2f (%s)\n", highest, topperName);
    printf("Lowest Marks    : %.2f\n", lowest);
}

int main(void) {
    int choice;

    printf("*********************************************\n");
    printf("*   STUDENT RECORD MANAGEMENT SYSTEM        *\n");
    printf("*********************************************\n");

    while (1) {
        displayMenu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addStudent();       break;
            case 2: displayAll();       break;
            case 3: searchByRollNo();   break;
            case 4: searchByName();     break;
            case 5: updateStudent();    break;
            case 6: deleteStudent();    break;
            case 7: sortByRollNo();     break;
            case 8: showStatistics();   break;
            case 9:
                printf("\nExiting Student Record System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select 1-9.\n");
        }
    }

    return 0;
}
