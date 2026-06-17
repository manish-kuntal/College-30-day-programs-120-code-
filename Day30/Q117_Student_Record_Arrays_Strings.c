#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

int main() {
    char names[MAX_STUDENTS][100];
    int rollNos[MAX_STUDENTS];
    float marks[MAX_STUDENTS];
    int n = 0, choice;

    while (1) {
        printf("\nStudent Record System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (n < MAX_STUDENTS) {
                printf("Enter Name: ");
                scanf(" %[^\n]", names[n]);
                printf("Enter Roll No: ");
                scanf("%d", &rollNos[n]);
                printf("Enter Marks: ");
                scanf("%f", &marks[n]);
                n++;
                printf("Added successfully!\n");
            } else {
                printf("Record full!\n");
            }
        } else if (choice == 2) {
            printf("\n--- Records ---\n");
            for (int i = 0; i < n; i++) {
                printf("Name: %s | Roll: %d | Marks: %.2f\n", names[i], rollNos[i], marks[i]);
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
