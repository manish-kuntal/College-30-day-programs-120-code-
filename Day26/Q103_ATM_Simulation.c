/*
 * Q103_ATM_Simulation.c
 * ---------------------
 * A realistic ATM simulation program with PIN authentication,
 * balance inquiry, deposit, withdrawal, and transaction history.
 *
 * Features:
 *   - PIN-based authentication (default PIN: 1234)
 *   - Balance inquiry
 *   - Cash deposit with validation
 *   - Cash withdrawal with balance check
 *   - Mini statement (last 10 transactions)
 *   - PIN change functionality
 *   - 3-attempt lockout for wrong PIN
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 10
#define INITIAL_BALANCE 50000.00
#define DEFAULT_PIN 1234
#define MAX_PIN_ATTEMPTS 3
#define MIN_WITHDRAWAL 100.0
#define MAX_WITHDRAWAL 25000.0

/* Transaction types */
#define TXN_DEPOSIT    1
#define TXN_WITHDRAWAL 2

/* Structure for transaction record */
typedef struct {
    int type;           /* 1 = Deposit, 2 = Withdrawal */
    double amount;
    double balanceAfter;
} Transaction;

/* Global ATM state */
double balance = INITIAL_BALANCE;
int pin = DEFAULT_PIN;
Transaction history[MAX_TRANSACTIONS];
int txnCount = 0;

/* Add a transaction to history (circular buffer for last 10) */
void addTransaction(int type, double amount, double balAfter) {
    int idx;
    if (txnCount < MAX_TRANSACTIONS) {
        idx = txnCount;
    } else {
        /* Shift all transactions left to make room */
        int i;
        for (i = 0; i < MAX_TRANSACTIONS - 1; i++) {
            history[i] = history[i + 1];
        }
        idx = MAX_TRANSACTIONS - 1;
    }
    history[idx].type = type;
    history[idx].amount = amount;
    history[idx].balanceAfter = balAfter;
    if (txnCount < MAX_TRANSACTIONS) {
        txnCount++;
    }
}

/* Display ATM menu */
void displayMenu(void) {
    printf("\n============================================\n");
    printf("             ATM MAIN MENU\n");
    printf("============================================\n");
    printf("  1. Check Balance\n");
    printf("  2. Deposit Cash\n");
    printf("  3. Withdraw Cash\n");
    printf("  4. Mini Statement\n");
    printf("  5. Change PIN\n");
    printf("  6. Exit\n");
    printf("============================================\n");
    printf("Enter your choice: ");
}

/* Balance inquiry */
void checkBalance(void) {
    printf("\n--------------------------------------------\n");
    printf("         BALANCE INQUIRY\n");
    printf("--------------------------------------------\n");
    printf("  Available Balance: Rs. %.2f\n", balance);
    printf("--------------------------------------------\n");
}

/* Deposit cash */
void depositCash(void) {
    double amount;

    printf("\n--------------------------------------------\n");
    printf("           CASH DEPOSIT\n");
    printf("--------------------------------------------\n");
    printf("Enter amount to deposit: Rs. ");

    if (scanf("%lf", &amount) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    /* Validate deposit amount */
    if (amount <= 0) {
        printf("Error: Deposit amount must be positive!\n");
        return;
    }
    if (amount > 100000.0) {
        printf("Error: Maximum deposit limit is Rs. 100000.00 per transaction.\n");
        return;
    }

    /* Process deposit */
    balance += amount;
    addTransaction(TXN_DEPOSIT, amount, balance);

    printf("\nDeposit Successful!\n");
    printf("Amount Deposited : Rs. %.2f\n", amount);
    printf("Updated Balance  : Rs. %.2f\n", balance);
    printf("--------------------------------------------\n");
}

/* Withdraw cash */
void withdrawCash(void) {
    double amount;

    printf("\n--------------------------------------------\n");
    printf("          CASH WITHDRAWAL\n");
    printf("--------------------------------------------\n");
    printf("Available Balance: Rs. %.2f\n", balance);
    printf("Enter amount to withdraw: Rs. ");

    if (scanf("%lf", &amount) != 1) {
        printf("Invalid input!\n");
        while (getchar() != '\n');
        return;
    }

    /* Validate withdrawal amount */
    if (amount <= 0) {
        printf("Error: Withdrawal amount must be positive!\n");
        return;
    }
    if (amount < MIN_WITHDRAWAL) {
        printf("Error: Minimum withdrawal is Rs. %.2f\n", MIN_WITHDRAWAL);
        return;
    }
    if (amount > MAX_WITHDRAWAL) {
        printf("Error: Maximum withdrawal per transaction is Rs. %.2f\n", MAX_WITHDRAWAL);
        return;
    }
    if (amount > balance) {
        printf("Error: Insufficient balance!\n");
        printf("Your current balance is Rs. %.2f\n", balance);
        return;
    }

    /* Check if amount is a multiple of 100 */
    if ((int)amount % 100 != 0) {
        printf("Error: Please enter amount in multiples of Rs. 100.\n");
        return;
    }

    /* Process withdrawal */
    balance -= amount;
    addTransaction(TXN_WITHDRAWAL, amount, balance);

    printf("\nWithdrawal Successful!\n");
    printf("Amount Withdrawn : Rs. %.2f\n", amount);
    printf("Remaining Balance: Rs. %.2f\n", balance);
    printf("\nPlease collect your cash.\n");
    printf("--------------------------------------------\n");
}

/* Display mini statement */
void miniStatement(void) {
    int i;

    printf("\n============================================\n");
    printf("           MINI STATEMENT\n");
    printf("============================================\n");

    if (txnCount == 0) {
        printf("  No transactions recorded yet.\n");
    } else {
        printf("  %-5s %-15s %-12s %-12s\n", "S.No", "Type", "Amount", "Balance");
        printf("  ----- --------------- ------------ ------------\n");
        for (i = 0; i < txnCount; i++) {
            printf("  %-5d %-15s Rs. %-8.2f Rs. %.2f\n",
                   i + 1,
                   (history[i].type == TXN_DEPOSIT) ? "DEPOSIT" : "WITHDRAWAL",
                   history[i].amount,
                   history[i].balanceAfter);
        }
    }

    printf("\n  Current Balance: Rs. %.2f\n", balance);
    printf("============================================\n");
}

/* Change PIN */
void changePIN(void) {
    int oldPin, newPin, confirmPin;

    printf("\n--------------------------------------------\n");
    printf("           CHANGE PIN\n");
    printf("--------------------------------------------\n");

    printf("Enter current PIN: ");
    scanf("%d", &oldPin);

    if (oldPin != pin) {
        printf("Error: Current PIN is incorrect!\n");
        return;
    }

    printf("Enter new PIN (4 digits): ");
    scanf("%d", &newPin);

    /* Validate new PIN */
    if (newPin < 1000 || newPin > 9999) {
        printf("Error: PIN must be a 4-digit number!\n");
        return;
    }
    if (newPin == pin) {
        printf("Error: New PIN cannot be the same as current PIN!\n");
        return;
    }

    printf("Confirm new PIN: ");
    scanf("%d", &confirmPin);

    if (newPin != confirmPin) {
        printf("Error: PINs do not match!\n");
        return;
    }

    pin = newPin;
    printf("\nPIN changed successfully!\n");
    printf("--------------------------------------------\n");
}

/* Authenticate user with PIN */
int authenticate(void) {
    int enteredPin, attempts = 0;

    printf("\n============================================\n");
    printf("        WELCOME TO ATM SERVICE\n");
    printf("============================================\n");

    while (attempts < MAX_PIN_ATTEMPTS) {
        printf("Enter your PIN: ");
        if (scanf("%d", &enteredPin) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            attempts++;
            continue;
        }

        if (enteredPin == pin) {
            printf("Authentication successful!\n");
            return 1;
        }

        attempts++;
        printf("Incorrect PIN! Attempts remaining: %d\n",
               MAX_PIN_ATTEMPTS - attempts);
    }

    printf("\nAccount LOCKED! Too many incorrect attempts.\n");
    printf("Please contact your bank for assistance.\n");
    return 0;
}

int main(void) {
    int choice;
    int running = 1;

    /* Authenticate user first */
    if (!authenticate()) {
        return 1;
    }

    /* Main ATM menu loop */
    while (running) {
        displayMenu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                depositCash();
                break;
            case 3:
                withdrawCash();
                break;
            case 4:
                miniStatement();
                break;
            case 5:
                changePIN();
                break;
            case 6:
                printf("\n============================================\n");
                printf("  Thank you for using our ATM services!\n");
                printf("  Please take your card.\n");
                printf("  Final Balance: Rs. %.2f\n", balance);
                printf("============================================\n");
                running = 0;
                break;
            default:
                printf("Invalid choice! Please select 1-6.\n");
        }
    }

    return 0;
}
