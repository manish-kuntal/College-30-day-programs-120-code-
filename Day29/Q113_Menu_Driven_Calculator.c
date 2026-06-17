#include <stdio.h>

int main() {
    int choice;
    float num1, num2;

    while (1) {
        printf("\nMenu Driven Calculator\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            break;
        }

        if (choice >= 1 && choice <= 4) {
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
            
            switch (choice) {
                case 1: printf("Result: %.2f\n", num1 + num2); break;
                case 2: printf("Result: %.2f\n", num1 - num2); break;
                case 3: printf("Result: %.2f\n", num1 * num2); break;
                case 4: 
                    if (num2 != 0) {
                        printf("Result: %.2f\n", num1 / num2); 
                    } else {
                        printf("Error: Division by zero!\n");
                    }
                    break;
            }
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
