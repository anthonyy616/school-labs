// 1.

// Task 1: Checks if a number is both odd and divisible by 5, otherwise returns false

#include <stdbool.h>
#include <stdio.h>

bool isOddAndDivisibleBy5(int num) {
    if (num % 2 != 0 && num % 5 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (isOddAndDivisibleBy5(number)) {
        printf("%d is odd and divisible by 5.\n", number);
    } else {
        printf("%d is either even or not divisible by 5 (or both).\n", number);
    }
    return 0;
}


//2.

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

bool isBetweenLowerAndUpper(char ch) {
    if (islower(ch) || isupper(ch)) {
        return true;
    } else {
        return false;
    }
}


int main() {
    char character;
    printf("Enter a character: ");
    scanf(" %c", &character); // Note the space before %c to consume any leftover newline
    if (isBetweenLowerAndUpper(character)) {
        printf("'%c' is either a lowercase or uppercase letter.\n", character);
    } else {
        printf("'%c' is not a lowercase or uppercase letter.\n", character);
    }
    return 0;
}

//3.

#include <stdbool.h>
#include <math.h>
#include <stdio.h>

bool isPerfectSquare(int num) {
    if (num < 0) {
        return false; // Negative numbers cannot be perfect squares
    }
    if (num == 0) {
        return true; // 0 is a perfect square
    }
    int root = round(sqrt(num));
    return (root * root == num);
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (isPerfectSquare(number)) {
        printf("%d is a perfect square.\n", number);
    } else {
        printf("%d is not a perfect square.\n", number);
    }
    return 0;
}


//4. 

#include <stdio.h>

int sumOfFirstNEven(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 2 * i;
    }
    return sum;
}

int main() {
    int num;
    printf("Enter the value of n: ");
    scanf("%d", &num);
    int sum = sumOfFirstNEven(num);
    printf("The sum of the first %d even numbers is: %d\n", num, sum);
    return 0;
}


// 5.

#include <stdio.h>
int countDigits(int num) {
    if (num == 0) {
        return 1;
    }
    int count = 0;
    if (num < 0) {
        num = -num; // Handle negative numbers
    }
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    int digits = countDigits(number);
    printf("The number of digits in %d is: %d\n", number, digits);
    return 0;
}