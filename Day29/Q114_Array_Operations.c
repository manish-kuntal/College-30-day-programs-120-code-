#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size = 0, choice, value, index;

    while (1) {
        printf("\nArray Operations System\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &size);
                if (size > MAX_SIZE) size = MAX_SIZE;
                printf("Enter %d elements: ", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                if (size == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 3:
                if (size >= MAX_SIZE) {
                    printf("Array is full.\n");
                } else {
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    printf("Enter index to insert (0 to %d): ", size);
                    scanf("%d", &index);
                    if (index >= 0 && index <= size) {
                        for (int i = size; i > index; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[index] = value;
                        size++;
                        printf("Element inserted successfully.\n");
                    } else {
                        printf("Invalid index.\n");
                    }
                }
                break;
            case 4:
                if (size == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Enter index to delete (0 to %d): ", size - 1);
                    scanf("%d", &index);
                    if (index >= 0 && index < size) {
                        for (int i = index; i < size - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        size--;
                        printf("Element deleted successfully.\n");
                    } else {
                        printf("Invalid index.\n");
                    }
                }
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
