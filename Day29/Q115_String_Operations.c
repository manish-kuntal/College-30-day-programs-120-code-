#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str1[100], str2[100];
    int choice;

    while (1) {
        printf("\nString Operations System\n");
        printf("1. String Length\n");
        printf("2. String Copy\n");
        printf("3. String Concatenation\n");
        printf("4. String Compare\n");
        printf("5. Convert to Uppercase\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                scanf(" %[^\n]", str1);
                printf("Length of string: %zu\n", strlen(str1));
                break;
            case 2:
                printf("Enter a string: ");
                scanf(" %[^\n]", str1);
                strcpy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;
            case 3:
                printf("Enter first string: ");
                scanf(" %[^\n]", str1);
                printf("Enter second string: ");
                scanf(" %[^\n]", str2);
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;
            case 4:
                printf("Enter first string: ");
                scanf(" %[^\n]", str1);
                printf("Enter second string: ");
                scanf(" %[^\n]", str2);
                if (strcmp(str1, str2) == 0) {
                    printf("Strings are identical.\n");
                } else {
                    printf("Strings are different.\n");
                }
                break;
            case 5:
                printf("Enter a string: ");
                scanf(" %[^\n]", str1);
                for (int i = 0; str1[i] != '\0'; i++) {
                    str1[i] = toupper(str1[i]);
                }
                printf("Uppercase string: %s\n", str1);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
