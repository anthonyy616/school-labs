#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. Recursive sum of natural numbers 1 + 2 + ... + n
int sumNatural(int n) {
    if (n <= 0) return 0;          // base case
    return n + sumNatural(n - 1);  // recursive case
}

// 2. Recursive sum of digits of a number
int sumDigits(int n) {
    if (n == 0) return 0;          // base case
    return (n % 10) + sumDigits(n / 10);  // last digit + sum of remaining
}

// 3. Recursive sum of elements in an integer array
int sumArray(int arr[], int size) {
    if (size <= 0) return 0;       // base case
    return arr[size - 1] + sumArray(arr, size - 1);
}

// 4. Recursive print string character by character
void printString(char str[]) {
    if (*str == '\0') {            // base case: end of string
        printf("\n");
        return;
    }
    printf("%c", *str);            // print current character
    printString(str + 1);          // recurse on next character
}

// 5. Recursive print string in reverse order
void printReverse(char str[]) {
    if (*str == '\0') {            // base case
        return;
    }
    printReverse(str + 1);         // first go to the end
    printf("%c", *str);            // then print on the way back
}

// 6. Recursive linear search in an array
int linearSearch(int arr[], int size, int key) {
    if (size <= 0) return -1;      // not found
    if (arr[size - 1] == key) return size - 1;  // found at last position
    return linearSearch(arr, size - 1, key);    // search in smaller array
}

int main() {
    int choice, n, result, size, key, index;
    char str[100];

    while (1) {
        printf("\n=== Recursion Menu ===\n");
        printf("1. Sum of natural numbers (1 to n)\n");
        printf("2. Sum of digits of a number\n");
        printf("3. Sum of array elements\n");
        printf("4. Print string character by character\n");
        printf("5. Print string in reverse order\n");
        printf("6. Linear search in array\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter n: ");
                scanf("%d", &n);
                if (n < 0) printf("Please enter a non-negative number.\n");
                else printf("Sum = %d\n", sumNatural(n));
                break;

            case 2:
                printf("Enter a number: ");
                scanf("%d", &n);
                if (n < 0) n = -n;  // handle negative numbers
                printf("Sum of digits = %d\n", sumDigits(n));
                break;

            case 3:
                printf("Enter array size: ");
                scanf("%d", &size);
                if (size <= 0) {
                    printf("Invalid size.\n");
                    break;
                }
                int arr[100];
                printf("Enter %d elements:\n", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("Sum of array = %d\n", sumArray(arr, size));
                break;

            case 4:
                printf("Enter a string: ");
                getchar();  // consume newline
                fgets(str, 100, stdin);
                str[strcspn(str, "\n")] = '\0';  // remove trailing newline
                printf("String printed character by character:\n");
                printString(str);
                break;

            case 5:
                printf("Enter a string: ");
                getchar();
                fgets(str, 100, stdin);
                str[strcspn(str, "\n")] = '\0';
                printf("String in reverse order:\n");
                printReverse(str);
                printf("\n");
                break;

            case 6:
                printf("Enter array size: ");
                scanf("%d", &size);
                if (size <= 0) {
                    printf("Invalid size.\n");
                    break;
                }
                int arr2[100];
                printf("Enter %d elements:\n", size);
                for (int i = 0; i < size; i++) {
                    scanf("%d", &arr2[i]);
                }
                printf("Enter key to search: ");
                scanf("%d", &key);
                index = linearSearch(arr2, size, key);
                if (index == -1)
                    printf("Key not found.\n");
                else
                    printf("Key found at index %d\n", index);
                break;

            case 7:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}