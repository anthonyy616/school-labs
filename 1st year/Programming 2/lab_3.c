#include <stdio.h>

// a. 

int main() {
    int lower, upper, i;

    printf("Enter the lower limit: ");
    scanf("%d", &lower);

    printf("Enter the upper limit: ");
    scanf("%d", &upper);

    if (lower <= upper) {
        for (i = lower; i <= upper; i++) {
            printf("%d ", i);
        }
    } else {
        // Swap lower and upper if upper is entered first
        for (i = upper; i <= lower; i++) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}




//b. For while

int main() {
    int lower, upper, i;

    printf("Enter the lower limit: ");
    scanf("%d", &lower);

    printf("Enter the upper limit: ");
    scanf("%d", &upper);

    if (lower <= upper) {
        i = lower;
        while (i <= upper) {
            printf("%d ", i);
            i++;
        }
    } else {
        i = upper;
        while (i <= lower) {
            printf("%d ", i);
            i++;
        }
    }

    printf("\n");
    return 0;
}

//b (ii.)

#include <stdio.h>

int main() {
    int lower, upper, i;

    printf("Enter the lower limit: ");
    scanf("%d", &lower);

    printf("Enter the upper limit: ");
    scanf("%d", &upper);

    if (lower <= upper) {
        i = lower;
        do {
            printf("%d ", i);
            i++;
        } while (i <= upper);
    } else {
        i = upper;
        do {
            printf("%d ", i);
            i++;
        } while (i <= lower);
    }

    printf("\n");
    return 0;
}


//c. Condition for good friend

// Without library functions

#include <stdio.h>

int main() {
    int num;

    printf("Enter a positive number: ");
    scanf("%d", &num);

    if (num == 64) {
        printf("%d is a good friend of 64!\n", num);
    } else {
        printf("%d is not a good friend of 64.\n", num);
    }

    return 0;
}

// ii. Power/Sqauare root functions

#include <stdio.h>
#include <math.h> // Include the math library for sqrt()

void checkGoodFriend(double num) {
    if (sqrt(num) == 8.0) {  // Check if the square root is 8
        printf("%.0lf is a good friend!\n", num);
    } else {
        printf("%.0lf is not a good friend.\n", num);
    }
}

int main() {
    double num; // Use double to handle potential floating-point results

    printf("Enter a number: ");
    scanf("%lf", &num); // Use %lf to read a double

    checkGoodFriend(num);

    return 0;
}

//d.

#include <stdio.h>

int main() {
    int num = 1;
    for (int i = 0; i < 4; i++) { //For columns
        for (int j = 0; j < 5; j++) { //For rows
            printf("%02d ", num);
            num += 2;
        }
        printf("\n");
    }
    return 0;
}


//ii.
#include <stdio.h>

int main() {
    int num = 1, i = 0, j;
    do {
        j = 0;
        do {
            printf("%02d ", num);
            num += 2;
            j++;
        } while (j < 5);
        printf("\n");
        i++;
    } while (i < 4);
    return 0;
}

//e.


#include <stdio.h>

int main() {
    int n = 4; // User input
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}


//ii.


#include <stdio.h>

int main() {
    int n = 4; // User input
    int i = n, j;
    while (i >= 1) {
        j = 0;
        while (j < i) {
            printf("%d", i);
            j++;
        }
        printf("\n");
        i--;
    }
    return 0;
}

