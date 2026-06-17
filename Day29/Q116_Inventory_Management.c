#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[100];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount < MAX_ITEMS) {
        inventory[itemCount].id = itemCount + 1;
        printf("Enter Item Name: ");
        scanf(" %[^\n]", inventory[itemCount].name);
        printf("Enter Quantity: ");
        scanf("%d", &inventory[itemCount].quantity);
        printf("Enter Price: ");
        scanf("%f", &inventory[itemCount].price);
        itemCount++;
        printf("Item added successfully!\n");
    } else {
        printf("Inventory is full!\n");
    }
}

void viewItems() {
    printf("\n--- Inventory Items ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("ID: %d | Name: %s | Qty: %d | Price: %.2f\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void updateQuantity() {
    int id, newQty;
    printf("Enter Item ID to update: ");
    scanf("%d", &id);
    if (id > 0 && id <= itemCount) {
        printf("Enter new quantity: ");
        scanf("%d", &newQty);
        inventory[id - 1].quantity = newQty;
        printf("Quantity updated successfully!\n");
    } else {
        printf("Invalid Item ID!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Update Quantity\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewItems(); break;
            case 3: updateQuantity(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
