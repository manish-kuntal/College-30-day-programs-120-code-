#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[100];
    char phone[15];
    char email[100];
} Contact;

Contact contacts[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount < MAX_CONTACTS) {
        printf("Enter Name: ");
        scanf(" %[^\n]", contacts[contactCount].name);
        printf("Enter Phone: ");
        scanf(" %[^\n]", contacts[contactCount].phone);
        printf("Enter Email: ");
        scanf(" %[^\n]", contacts[contactCount].email);
        contactCount++;
        printf("Contact added successfully!\n");
    } else {
        printf("Contact book is full!\n");
    }
}

void viewContacts() {
    printf("\n--- Contact List ---\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s | Phone: %s | Email: %s\n", 
               i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void searchContact() {
    char searchName[100];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);
    
    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Found - Name: %s | Phone: %s | Email: %s\n", 
                   contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
