#include <stdio.h>
#include <string.h>

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} BankAccount;

void createAccount(BankAccount *acc) {
    printf("Enter Account Number: ");
    scanf("%d", &acc->accountNumber);
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", acc->name);
    acc->balance = 0.0;
    printf("Account created successfully!\n");
}

void deposit(BankAccount *acc) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        acc->balance += amount;
        printf("Deposited %.2f successfully. New Balance: %.2f\n", amount, acc->balance);
    } else {
        printf("Invalid amount!\n");
    }
}

void withdraw(BankAccount *acc) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= acc->balance) {
        acc->balance -= amount;
        printf("Withdrawn %.2f successfully. New Balance: %.2f\n", amount, acc->balance);
    } else {
        printf("Invalid amount or insufficient balance!\n");
    }
}

void checkBalance(BankAccount acc) {
    printf("Account Holder: %s\n", acc.name);
    printf("Current Balance: %.2f\n", acc.balance);
}

int main() {
    BankAccount myAccount;
    int choice, created = 0;

    while (1) {
        printf("\nBank Account System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                createAccount(&myAccount); 
                created = 1;
                break;
            case 2: 
                if (created) deposit(&myAccount); 
                else printf("Create an account first!\n");
                break;
            case 3: 
                if (created) withdraw(&myAccount); 
                else printf("Create an account first!\n");
                break;
            case 4: 
                if (created) checkBalance(myAccount); 
                else printf("Create an account first!\n");
                break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
