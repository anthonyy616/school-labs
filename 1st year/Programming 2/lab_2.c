#include <stdio.h>

// a) Logical Operators
void logical_operators() {
    printf("Logical Operators:\n");

    printf("AND (&&):\n");
    printf("0 && 0 = %d\n", 0 && 0);
    printf("0 && 1 = %d\n", 0 && 1);
    printf("1 && 0 = %d\n", 1 && 0);
    printf("1 && 1 = %d\n", 1 && 1);

    printf("\nOR (||):\n");
    printf("0 || 0 = %d\n", 0 || 0);
    printf("0 || 1 = %d\n", 0 || 1);
    printf("1 || 0 = %d\n", 1 || 0);
    printf("1 || 1 = %d\n", 1 || 1);

    printf("\nNOT (!):\n");
    printf("!0 = %d\n", !0);
    printf("!1 = %d\n", !1);
}

int main() {
    logical_operators();
    return 0;
}




#include <stdio.h>

// b) Find the smallest of three numbers
void find_smallest() {
    int num1, num2, num3, smallest;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    smallest = num1;
    if (num2 < smallest) {
        smallest = num2;
    }
    if (num3 < smallest) {
        smallest = num3;
    }

    printf("The smallest number is: %d\n", smallest);
}

int main() {
    find_smallest();
    return 0;
}



#include <stdio.h>

// c) Find the smallest using ternary operator
void find_smallest_ternary() {
    int num1, num2, num3, smallest;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    smallest = (num1 < num2) ? ((num1 < num3) ? num1 : num3) : ((num2 < num3) ? num2 : num3);

    printf("The smallest number is: %d\n", smallest);
}

int main() {
    find_smallest_ternary();
    return 0;
}


#include <stdio.h>
#include <stdio.h>

// d) Grade calculation 
void calculate_grade() {
    float labs, quizzes, midterm, final, total;
    char grade;

    printf("Enter labs score: ");
    scanf("%f", &labs);
    printf("Enter quizzes score: ");
    scanf("%f", &quizzes);
    printf("Enter midterm score: ");
    scanf("%f", &midterm);
    printf("Enter final score: ");
    scanf("%f", &final);

    total = labs * 0.2 + quizzes * 0.1 + midterm * 0.3 + final * 0.4;

    if (total >= 85 && total <= 100) { // Corrected range check
        grade = 'A';
    } else if (total >= 75 && total < 85) { // Corrected range check
        grade = 'B';
    } else if (total >= 60 && total < 75) { // Corrected range check
        grade = 'C';
    } else if (total >= 50 && total < 60) { // Corrected range check
        grade = 'D';
    } else {
        grade = 'F';
    }

    printf("Total grade: %.2f\n", total);
    printf("Letter grade: %c\n", grade);
}

int main() {
    calculate_grade();
    return 0;
}


#include <stdio.h>

// e) Triangle validation
void triangle_validation() {
    int side1, side2, side3;

    printf("Enter three side lengths: ");
    scanf("%d %d %d", &side1, &side2, &side3);

    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
        printf("Valid triangle.\n");
    } else {
        printf("Invalid triangle.\n");
    }
}

int main() {
    triangle_validation();
    return 0;
}



#include <stdio.h>

// f) Positive, negative, or zero using if-else
void check_number_ifelse() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if (num > 0) {
        printf("%d is positive.\n", num);
    } else if (num < 0) {
        printf("%d is negative.\n", num);
    } else {
        printf("%d is zero.\n", num);
    }
}

int main() {
    check_number_ifelse();
    return 0;
}