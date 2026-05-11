#include <stdio.h>

// Function to swap two integers by value
void swap_by_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swap_by_value: a = %d, b = %d\n", a, b);
}

// Function to swap two integers by reference (using pointers)
void swap_by_reference(int *pa, int *pb) {
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
    printf("Inside swap_by_reference: *pa = %d, *pb = %d\n", *pa, *pb);
}

int main() {
    printf("\n--- Part A: Swapping Using Call-by-Reference ---\n");
    int num1 = 10, num2 = 20;

    printf("Before swap (call-by-value): num1 = %d, num2 = %d\n", num1, num2);
    swap_by_value(num1, num2);
    printf("After swap (call-by-value): num1 = %d, num2 = %d (no change)\n", num1, num2);

    printf("\nBefore swap (call-by-reference): num1 = %d, num2 = %d\n", num1, num2);
    swap_by_reference(&num1, &num2);
    printf("After swap (call-by-reference): num1 = %d, num2 = %d (values swapped)\n", num1, num2);
    return 0;
}



//2.

#include <stdio.h>
#include <stdlib.h>

// Function to input integer array elements using pointer notation
void input_1d_array(int *arr, int size) {
    printf("Enter %d integer elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", (arr + i)); // Equivalent to &arr[i]
    }
}

// Function to output integer array elements using pointer notation
void output_1d_array(int *arr, int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i)); // Equivalent to arr[i]
    }
    printf("\n");
}

// Function to calculate the sum of integer array elements using pointer notation
int sum_1d_array(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i); // Equivalent to arr[i]
    }
    return sum;
}

// Function to calculate the average of integer array elements using pointer notation
float average_1d_array(int *arr, int size) {
    if (size <= 0) {
        return 0.0;
    }
    int sum = sum_1d_array(arr, size);
    return (float)sum / size;
}

int main() {
    printf("\n--- Part B: Working with Arrays Using Pointers ---\n");
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1; // Use a non-zero return value for error
    }

    int *numbers = (int *)malloc(size * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Use a non-zero return value for error
    }

    input_1d_array(numbers, size);
    output_1d_array(numbers, size);

    int sum = sum_1d_array(numbers, size);
    printf("Sum of the array elements: %d\n", sum);

    float average = average_1d_array(numbers, size);
    printf("Average of the array elements: %.2f\n", average);

    free(numbers); // Remember to free dynamically allocated memory
    return 0;
}



//3.

#include <stdio.h>
#include <string.h>

// Function to calculate the length of a string using pointer arithmetic
int string_length(const char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

// Function to copy a string using pointer arithmetic
char* string_copy(char *dest, const char *src) {
    char *original_dest = dest; // Store the original destination pointer
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Null-terminate the destination string
    return original_dest; // Return a pointer to the beginning of the destination string
}

// Function to concatenate two strings using pointer arithmetic
char* string_concatenate(char *result, const char *str1, const char *str2) {
    char *original_result = result;

    // Copy str1 to result
    while (*str1 != '\0') {
        *result = *str1;
        result++;
        str1++;
    }

    // Copy str2 to the end of result
    while (*str2 != '\0') {
        *result = *str2;
        result++;
        str2++;
    }

    *result = '\0'; // Null-terminate the result string
    return original_result;
}

int main() {
    printf("\n--- Part C: String Manipulation Using Pointers ---\n");
    char input1[100], input2[100], combined[200], copied[100];
    int len;

    printf("Enter the first string: ");
    scanf("%99s", input1); // Limit input to prevent buffer overflow

    printf("Enter the second string: ");
    scanf("%99s", input2); // Limit input to prevent buffer overflow

    // Calculate length
    len = string_length(input1);
    printf("Length of '%s': %d\n", input1, len);

    // Copy string
    string_copy(copied, input1);
    printf("Copied string: '%s'\n", copied);

    // Concatenate strings
    string_concatenate(combined, input1, input2);
    printf("Concatenation of '%s' and '%s': '%s'\n", input1, input2, combined);
    return 0;
}
