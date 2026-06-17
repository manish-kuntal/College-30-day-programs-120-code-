#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100

char names[MAX_RECORDS][50];
int ages[MAX_RECORDS];
int count = 0;

void addRecord() {
    if (count < MAX_RECORDS) {
        printf("Enter Name: ");
        scanf(" %[^\n]", names[count]);
        printf("Enter Age: ");
        scanf("%d", &ages[count]);
        count++;
        printf("Record added!\n");
    } else {
        printf("Database full!\n");
    }
}

void viewRecords() {
    printf("\n--- All Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Age: %d\n", i + 1, names[i], ages[i]);
    }
}

void searchRecord() {
    char search[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]", search);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(names[i], search) == 0) {
            printf("Found - Name: %s, Age: %d\n", names[i], ages[i]);
            found = 1;
            break;
        }
    }
    if (!found) printf("Record not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nComplete Mini Project (Database)\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Search Record\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecord(); break;
            case 2: viewRecords(); break;
            case 3: searchRecord(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
