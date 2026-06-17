#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 50

int main() {
    char books[MAX_BOOKS][100];
    int available[MAX_BOOKS];
    int n = 0, choice, i;
    char search[100];

    while (1) {
        printf("\nMini Library System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (n < MAX_BOOKS) {
                    printf("Enter Book Name: ");
                    scanf(" %[^\n]", books[n]);
                    available[n] = 1;
                    n++;
                    printf("Added successfully!\n");
                } else {
                    printf("Library full!\n");
                }
                break;
            case 2:
                printf("\n--- Books ---\n");
                for (i = 0; i < n; i++) {
                    printf("%d. %s - %s\n", i + 1, books[i], available[i] ? "Available" : "Issued");
                }
                break;
            case 3:
                printf("Enter book name to search: ");
                scanf(" %[^\n]", search);
                int found = 0;
                for (i = 0; i < n; i++) {
                    if (strcmp(books[i], search) == 0) {
                        printf("Found: %s - %s\n", books[i], available[i] ? "Available" : "Issued");
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Not found.\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
