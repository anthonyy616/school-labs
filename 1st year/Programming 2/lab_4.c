

//1Geometric computations

//1a. Area of rectangle

#include <stdio.h>

void area_rectangle() {
    int length, breadth, area; 
    printf("Enter the length of the rectangle: ");
    scanf("%d", &length);

    printf("Enter the breadth of the rectangle: ");
    scanf("%d", &breadth);

    area = length * breadth; // Calculate the area

    printf("The area of the rectangle is: %d\n", area);
}

int main() {
    area_rectangle();
    return 0;
}


 //1b. Perimeter of rectangle
#include <stdio.h>
void perimeter_rectangle() {
    int length, breadth, perimeter;
    printf("Enter the length of the rectangle: ");
    scanf("%d", &length);

    printf("Enter the breadth of the rectangle: ");
    scanf("%d", &breadth);

    perimeter = 2 * (length + breadth);

    printf("The perimeter of the rectangle is: %d", perimeter);
}

int main() {
    perimeter_rectangle();
    return 0;
}


//2. 

//a. Max of three integers

#include <stdio.h>

void max_of_three () {
    int a, b, c, max;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("Enter the third number: ");
    scanf("%d", &c);
    max = (a > b) ? (a > c ? a : c) : ( // Using ternary operators
        b > c ? b : c);
        printf("The maximum of the three numbers is: %d\n", max);
    }

int main () {
    max_of_three();
    return 0; 
}

//b. Minimum of three integers
#include <stdio.h>

void min_of_three () {
    int a, b, c, min;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("Enter the third number: ");
    scanf("%d", &c);
    
    min = a;

    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
        
    printf("The minimum of the three numbers is: %d\n", min);
    }

int main () {
    min_of_three();
    return 0;
} 


//c. Sum of natural numbers 
#include <stdio.h>
void sum_natural_numbers(int n);

int main() {
    int n;

    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        sum_natural_numbers(n);
    }

    return 0;
}

// Function definition
void sum_natural_numbers(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    printf("Sum of first %d natural numbers: %d\n", n, sum);
}

//d. 

#include <stdio.h>
void sum_first_n_odds(int n);

int main() {
    int n;

    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        sum_first_n_odds(n);
    }

    return 0;
}

// Function definition
void sum_first_n_odds(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (2 * i + 1);
    }
    printf("Sum of the first %d odd numbers: %d\n", n, sum);
}

// e. Average of numbers

#include <stdio.h>

// Function prototype
void average_n_numbers(int n);

int main() {
    int n;

    printf("Enter the number of numbers to average: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        average_n_numbers(n);
    }

    return 0;
}

// Function definition
#include <stdio.h>
void average_n_numbers(int n) {
    double sum = 0.0;
    double num;

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%lf", &num);
        sum += num;
    }

    double average = sum / n;
    printf("Average of the %d numbers: %.2lf\n", n, average);
}






//3. Logical Operations
#include <stdio.h>

int is_multiple(int x, int y) {
    if (y == 0) {
        // Handle division by zero (undefined)
        return 0; // Or you could return an error code, etc.
    }
    return (x % y == 0);
}

int main() {
    printf("Is 10 a multiple of 5? %d\n", is_multiple(10, 5));
    printf("Is 7 a multiple of 3? %d\n", is_multiple(7, 3));
    return 0;
}

//b. 

#include <stdio.h>

int is_space(char c) {
    return (c == ' ');
}

int main() {
    printf("Is ' ' a space? %d\n", is_space(' '));
    printf("Is 'a' a space? %d\n", is_space('a'));
    return 0;
}

//c. 
#include <stdio.h>

int is_power_of_two(unsigned int n) {
    if (n == 0) {
        return 0; // 0 is not a power of 2
    }
    return (n && !(n & (n - 1)));
}

int main() {
    printf("Is 8 a power of two? %d\n", is_power_of_two(8));
    printf("Is 9 a power of two? %d\n", is_power_of_two(9));
    printf("Is 0 a power of two? %d\n", is_power_of_two(0));
    printf("Is 1 a power of two? %d\n", is_power_of_two(1));
    return 0;
}