//1. Basic Array Operations

#include <stdio.h>
#include <stdlib.h>

void inputArray(int arr[], int size) {
    printf("Enter %d integer values for the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int size) {
    printf("The values in the array are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;

    printf("Enter the size of the array (1 to 100): ");
    scanf("%d", &size);

    if (size < 1 || size > 100) {
        printf("Invalid array size. Size must be between 1 and 100.\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    inputArray(arr, size);
    displayArray(arr, size);

    free(arr);
    return 0;
}


//2a. Summation and Average Calculation

#include <stdio.h>
#include <stdlib.h>

void inputArray(int arr[], int size) {
    printf("Enter %d integer values for the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int size) {
    printf("The values in the array are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int calculateSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

float calculateAverage(int sum, int size) {
    if (size > 0) {
        return (float)sum / size;
    } else {
        return 0; // Avoid division by zero
    }
}

int main() {
    int size;

    printf("Enter the size of the array (1 to 100): ");
    scanf("%d", &size);

    if (size < 1 || size > 100) {
        printf("Invalid array size. Size must be between 1 and 100.\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    inputArray(arr, size);
    displayArray(arr, size);

    int sum = calculateSum(arr, size);
    float average = calculateAverage(sum, size);

    printf("Sum of the array elements: %d\n", sum);
    printf("Average of the array elements: %.2f\n", average);

    free(arr);
    return 0;
}

//2b. 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MAX and INT_MIN

void inputArray(int arr[], int size) {
    printf("Enter %d integer values for the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int size) {
    printf("The values in the array are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int calculateSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

float calculateAverage(int sum, int size) {
    if (size > 0) {
        return (float)sum / size;
    } else {
        return 0;
    }
}

int findMinimum(int arr[], int size) {
    if (size <= 0) {
        fprintf(stderr, "Error: Array size is invalid in findMinimum.\n");
        return INT_MAX; // Return a large value to indicate error
    }
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int findMaximum(int arr[], int size) {
    if (size <= 0) {
        fprintf(stderr, "Error: Array size is invalid in findMaximum.\n");
        return INT_MIN; // Return a small value to indicate error
    }
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int size;

    printf("Enter the size of the array (1 to 100): ");
    scanf("%d", &size);

    if (size < 1 || size > 100) {
        printf("Invalid array size. Size must be between 1 and 100.\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    inputArray(arr, size);
    displayArray(arr, size);

    int sum = calculateSum(arr, size);
    float average = calculateAverage(sum, size);
    int minVal = findMinimum(arr, size);
    int maxVal = findMaximum(arr, size);

    printf("Sum of the array elements: %d\n", sum);
    printf("Average of the array elements: %.2f\n", average);
    printf("Minimum value in the array: %d\n", minVal);
    printf("Maximum value in the array: %d\n", maxVal);

    free(arr);
    return 0;
}