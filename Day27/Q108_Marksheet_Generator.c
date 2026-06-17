/*
 * Q108_Marksheet_Generator.c
 * --------------------------
 * A marksheet generation system that accepts student details
 * and marks for multiple subjects, then generates a formatted marksheet.
 *
 * Features:
 *   - Add student with multiple subjects
 *   - Calculate total marks and percentage
 *   - Auto-assign grade based on percentage
 *   - Pass/Fail determination (min 33% per subject, 40% overall)
 *   - Formatted marksheet printout
 *   - Class-wide statistics
 *   - Support for multiple students
 */

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_SUBJECTS 8
#define NAME_LEN 50
#define SUBJ_LEN 30
#define MAX_MARKS 100
#define MIN_PASS_MARKS 33
#define MIN_PASS_PERCENT 40.0

/* Student marksheet structure */
typedef struct {
    int rollNo;
    char name[NAME_LEN];
    char className[20];
    int numSubjects;
    char subjects[MAX_SUBJECTS][SUBJ_LEN];
    float marks[MAX_SUBJECTS];
    float totalMarks;
    float maxMarks;
    float percentage;
    char grade[3];
    int passed;         /* 1 = pass, 0 = fail */
    int isActive;
} StudentMark;

StudentMark students[MAX_STUDENTS];
int studentCount = 0;

/* Calculate grade from percentage */
void calculateGrade(StudentMark *s) {
    if (s->percentage >= 90.0) strcpy(s->grade, "A+");
    else if (s->percentage >= 80.0) strcpy(s->grade, "A");
    else if (s->percentage >= 70.0) strcpy(s->grade, "B+");
    else if (s->percentage >= 60.0) strcpy(s->grade, "B");
    else if (s->percentage >= 50.0) strcpy(s->grade, "C");
    else if (s->percentage >= 40.0) strcpy(s->grade, "D");
    else strcpy(s->grade, "F");
}

/* Check pass/fail (each subject >= 33 and overall >= 40%) */
int checkPassFail(StudentMark *s) {
    int i;
    /* Check individual subject minimum */
    for (i = 0; i < s->numSubjects; i++) {
        if (s->marks[i] < MIN_PASS_MARKS) {
            return 0;  /* Failed in at least one subject */
        }
    }
    /* Check overall percentage */
    if (s->percentage < MIN_PASS_PERCENT) {
        return 0;
    }
    return 1;
}

/* Calculate total, percentage, grade, and pass/fail */
void calculateResults(StudentMark *s) {
    int i;
    s->totalMarks = 0;
    s->maxMarks = s->numSubjects * MAX_MARKS;

    for (i = 0; i < s->numSubjects; i++) {
        s->totalMarks += s->marks[i];
    }

    s->percentage = (s->totalMarks / s->maxMarks) * 100.0f;
    calculateGrade(s);
    s->passed = checkPassFail(s);
}

/* Display menu */
void displayMenu(void) {
    printf("\n============================================\n");
    printf("       MARKSHEET GENERATION SYSTEM\n");
    printf("============================================\n");
    printf("  1. Add Student Marks\n");
    printf("  2. Generate Marksheet\n");
    printf("  3. Display All Results\n");
    printf("  4. Class Statistics\n");
    printf("  5. Subject-wise Analysis\n");
    printf("  6. Toppers List\n");
    printf("  7. Failed Students List\n");
    printf("  8. Exit\n");
    printf("============================================\n");
    printf("Enter your choice: ");
}

/* Add student marks */
void addStudentMarks(void) {
    StudentMark *s;
    int i, rollNo;

    if (studentCount >= MAX_STUDENTS) {
        printf("Error: Maximum student limit reached!\n");
        return;
    }

    printf("\n--- Add Student Marks ---\n");
    printf("Enter Roll Number: ");
    if (scanf("%d", &rollNo) != 1 || rollNo <= 0) {
        printf("Error: Invalid roll number!\n");
        while (getchar() != '\n');
        return;
    }

    /* Check duplicate roll number */
    for (i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo && students[i].isActive) {
            printf("Error: Roll number %d already exists!\n", rollNo);
            return;
        }
    }

    s = &students[studentCount];
    s->rollNo = rollNo;

    printf("Enter Student Name: ");
    getchar();
    fgets(s->name, NAME_LEN, stdin);
    s->name[strcspn(s->name, "\n")] = '\0';

    if (strlen(s->name) == 0) {
        printf("Error: Name cannot be empty!\n");
        return;
    }

    printf("Enter Class: ");
    fgets(s->className, 20, stdin);
    s->className[strcspn(s->className, "\n")] = '\0';

    printf("Enter number of subjects (1-%d): ", MAX_SUBJECTS);
    if (scanf("%d", &s->numSubjects) != 1 ||
        s->numSubjects < 1 || s->numSubjects > MAX_SUBJECTS) {
        printf("Error: Invalid number of subjects!\n");
        while (getchar() != '\n');
        return;
    }

    /* Get subject names and marks */
    for (i = 0; i < s->numSubjects; i++) {
        printf("\nSubject %d:\n", i + 1);
        printf("  Name: ");
        getchar();
        fgets(s->subjects[i], SUBJ_LEN, stdin);
        s->subjects[i][strcspn(s->subjects[i], "\n")] = '\0';

        printf("  Marks (0-%d): ", MAX_MARKS);
        if (scanf("%f", &s->marks[i]) != 1 ||
            s->marks[i] < 0 || s->marks[i] > MAX_MARKS) {
            printf("Error: Invalid marks! Must be 0-%d.\n", MAX_MARKS);
            while (getchar() != '\n');
            return;
        }
    }

    /* Calculate results */
    calculateResults(s);
    s->isActive = 1;
    studentCount++;

    printf("\nStudent marks added successfully!\n");
    printf("Result: %s | Percentage: %.2f%% | Grade: %s\n",
           s->passed ? "PASS" : "FAIL", s->percentage, s->grade);
}

/* Generate formatted marksheet */
void generateMarksheet(void) {
    int rollNo, idx = -1, i;
    StudentMark *s;

    printf("\nEnter Roll Number: ");
    if (scanf("%d", &rollNo) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    for (i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo && students[i].isActive) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Student with Roll No %d not found!\n", rollNo);
        return;
    }

    s = &students[idx];

    printf("\n+========================================================+\n");
    printf("|                    MARKSHEET                            |\n");
    printf("+========================================================+\n");
    printf("| Roll No  : %-43d |\n", s->rollNo);
    printf("| Name     : %-43s |\n", s->name);
    printf("| Class    : %-43s |\n", s->className);
    printf("+--------------------------------------------------------+\n");
    printf("| %-4s %-25s %-10s %-10s    |\n", "S.No", "Subject", "Marks", "Status");
    printf("+--------------------------------------------------------+\n");

    for (i = 0; i < s->numSubjects; i++) {
        printf("| %-4d %-25s %-10.0f %-10s    |\n",
               i + 1, s->subjects[i], s->marks[i],
               (s->marks[i] >= MIN_PASS_MARKS) ? "Pass" : "FAIL");
    }

    printf("+--------------------------------------------------------+\n");
    printf("| Total Marks     : %-8.0f / %-8.0f                   |\n",
           s->totalMarks, s->maxMarks);
    printf("| Percentage      : %-8.2f%%                            |\n", s->percentage);
    printf("| Grade           : %-8s                               |\n", s->grade);
    printf("| Result          : %-8s                               |\n",
           s->passed ? "PASS" : "FAIL");
    printf("+========================================================+\n");
}

/* Display all results */
void displayAllResults(void) {
    int i, count = 0;

    printf("\n====================================================================\n");
    printf("                      ALL STUDENT RESULTS\n");
    printf("====================================================================\n");
    printf("%-8s %-20s %-10s %-10s %-6s %-8s\n",
           "Roll No", "Name", "Total", "Percent", "Grade", "Result");
    printf("-------- -------------------- ---------- ---------- ------ --------\n");

    for (i = 0; i < studentCount; i++) {
        if (students[i].isActive) {
            printf("%-8d %-20s %-5.0f/%-4.0f %-9.2f%% %-6s %-8s\n",
                   students[i].rollNo, students[i].name,
                   students[i].totalMarks, students[i].maxMarks,
                   students[i].percentage, students[i].grade,
                   students[i].passed ? "PASS" : "FAIL");
            count++;
        }
    }

    if (count == 0)
        printf("  No student records found.\n");
    else
        printf("\nTotal students: %d\n", count);
}

/* Class statistics */
void classStatistics(void) {
    int i, count = 0, passCount = 0, failCount = 0;
    float totalPercentage = 0, highest = 0, lowest = 100;
    char topperName[NAME_LEN] = "";

    for (i = 0; i < studentCount; i++) {
        if (students[i].isActive) {
            count++;
            totalPercentage += students[i].percentage;
            if (students[i].passed) passCount++;
            else failCount++;

            if (students[i].percentage > highest) {
                highest = students[i].percentage;
                strcpy(topperName, students[i].name);
            }
            if (students[i].percentage < lowest) {
                lowest = students[i].percentage;
            }
        }
    }

    if (count == 0) {
        printf("No data available for statistics.\n");
        return;
    }

    printf("\n--- Class Statistics ---\n");
    printf("Total Students    : %d\n", count);
    printf("Passed            : %d (%.1f%%)\n", passCount, (float)passCount / count * 100);
    printf("Failed            : %d (%.1f%%)\n", failCount, (float)failCount / count * 100);
    printf("Class Average     : %.2f%%\n", totalPercentage / count);
    printf("Highest Percentage: %.2f%% (%s)\n", highest, topperName);
    printf("Lowest Percentage : %.2f%%\n", lowest);
}

/* Subject-wise analysis */
void subjectAnalysis(void) {
    int i, j, count;
    float total, highest, lowest;

    if (studentCount == 0 || !students[0].isActive) {
        printf("No data available.\n");
        return;
    }

    printf("\n--- Subject-wise Analysis ---\n");
    printf("(Based on first student's subjects)\n\n");

    /* Use first active student's subject list as reference */
    for (j = 0; j < students[0].numSubjects; j++) {
        total = 0;
        highest = 0;
        lowest = MAX_MARKS;
        count = 0;

        for (i = 0; i < studentCount; i++) {
            if (students[i].isActive && j < students[i].numSubjects) {
                total += students[i].marks[j];
                if (students[i].marks[j] > highest) highest = students[i].marks[j];
                if (students[i].marks[j] < lowest) lowest = students[i].marks[j];
                count++;
            }
        }

        if (count > 0) {
            printf("%-20s: Avg=%.2f | High=%.0f | Low=%.0f\n",
                   students[0].subjects[j], total / count, highest, lowest);
        }
    }
}

/* Toppers list */
void toppersList(void) {
    int i, j, count = 0;
    int indices[MAX_STUDENTS];

    /* Collect active students */
    for (i = 0; i < studentCount; i++) {
        if (students[i].isActive) {
            indices[count++] = i;
        }
    }

    if (count == 0) {
        printf("No data available.\n");
        return;
    }

    /* Sort indices by percentage (descending) */
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (students[indices[j]].percentage < students[indices[j + 1]].percentage) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    printf("\n--- Toppers List (Top 5) ---\n");
    printf("%-6s %-8s %-20s %-10s %-6s\n", "Rank", "Roll No", "Name", "Percent", "Grade");
    printf("------ -------- -------------------- ---------- ------\n");

    for (i = 0; i < count && i < 5; i++) {
        printf("%-6d %-8d %-20s %-9.2f%% %-6s\n",
               i + 1, students[indices[i]].rollNo, students[indices[i]].name,
               students[indices[i]].percentage, students[indices[i]].grade);
    }
}

/* Failed students list */
void failedStudentsList(void) {
    int i, count = 0;

    printf("\n--- Failed Students ---\n");

    for (i = 0; i < studentCount; i++) {
        if (students[i].isActive && !students[i].passed) {
            int j;
            printf("Roll No: %d | Name: %s | Percentage: %.2f%%\n",
                   students[i].rollNo, students[i].name, students[i].percentage);

            /* Show failed subjects */
            printf("  Failed subjects: ");
            for (j = 0; j < students[i].numSubjects; j++) {
                if (students[i].marks[j] < MIN_PASS_MARKS) {
                    printf("%s(%.0f) ", students[i].subjects[j], students[i].marks[j]);
                }
            }
            printf("\n");
            count++;
        }
    }

    if (count == 0)
        printf("  No failed students. Congratulations!\n");
    else
        printf("\nTotal failed: %d\n", count);
}

int main(void) {
    int choice;

    printf("*********************************************\n");
    printf("*    MARKSHEET GENERATION SYSTEM v1.0       *\n");
    printf("*********************************************\n");

    while (1) {
        displayMenu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: addStudentMarks();      break;
            case 2: generateMarksheet();    break;
            case 3: displayAllResults();    break;
            case 4: classStatistics();      break;
            case 5: subjectAnalysis();      break;
            case 6: toppersList();          break;
            case 7: failedStudentsList();   break;
            case 8:
                printf("\nExiting Marksheet Generation System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select 1-8.\n");
        }
    }

    return 0;
}
