#include <stdio.h>
#include <string.h>

#define MAX_TICKETS 50

int tickets[MAX_TICKETS] = {0}; // 0 = available, 1 = booked

void viewTickets() {
    printf("\n--- Available Tickets ---\n");
    for (int i = 0; i < MAX_TICKETS; i++) {
        if (tickets[i] == 0) {
            printf("%d ", i + 1);
        } else {
            printf("[X] ");
        }
        if ((i + 1) % 10 == 0) printf("\n");
    }
    printf("\n");
}

void bookTicket() {
    int tNo;
    printf("Enter ticket number to book (1-%d): ", MAX_TICKETS);
    scanf("%d", &tNo);
    
    if (tNo >= 1 && tNo <= MAX_TICKETS) {
        if (tickets[tNo - 1] == 0) {
            tickets[tNo - 1] = 1;
            printf("Ticket %d booked successfully!\n", tNo);
        } else {
            printf("Sorry, Ticket %d is already booked.\n", tNo);
        }
    } else {
        printf("Invalid ticket number!\n");
    }
}

void cancelTicket() {
    int tNo;
    printf("Enter ticket number to cancel (1-%d): ", MAX_TICKETS);
    scanf("%d", &tNo);
    
    if (tNo >= 1 && tNo <= MAX_TICKETS) {
        if (tickets[tNo - 1] == 1) {
            tickets[tNo - 1] = 0;
            printf("Ticket %d cancelled successfully!\n", tNo);
        } else {
            printf("Ticket %d is not booked yet.\n", tNo);
        }
    } else {
        printf("Invalid ticket number!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nTicket Booking System\n");
        printf("1. View Tickets\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: viewTickets(); break;
            case 2: bookTicket(); break;
            case 3: cancelTicket(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
