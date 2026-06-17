#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[100];
    char author[100];
    int isIssued;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount < MAX_BOOKS) {
        library[bookCount].id = bookCount + 1;
        printf("Enter Book Title: ");
        scanf(" %[^\n]", library[bookCount].title);
        printf("Enter Book Author: ");
        scanf(" %[^\n]", library[bookCount].author);
        library[bookCount].isIssued = 0;
        bookCount++;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full!\n");
    }
}

void viewBooks() {
    printf("\n--- Library Books ---\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d | Title: %s | Author: %s | Status: %s\n", 
               library[i].id, library[i].title, library[i].author, 
               library[i].isIssued ? "Issued" : "Available");
    }
}

void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    if (id > 0 && id <= bookCount) {
        if (!library[id-1].isIssued) {
            library[id-1].isIssued = 1;
            printf("Book issued successfully!\n");
        } else {
            printf("Book is already issued!\n");
        }
    } else {
        printf("Invalid Book ID!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Issue Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: issueBook(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
