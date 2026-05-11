//1.

#include <limits.h>
#include <stdio.h>

int main() {
    printf("Number of bits in a byte: %d\n", CHAR_BIT);
    return 0;
}


//2.

#include <stdio.h>

int main() {
    printf("char: %zu bytes\n", sizeof(char));
    printf("int: %zu bytes\n", sizeof(int));
    printf("float: %zu bytes\n", sizeof(float));
    printf("double: %zu bytes\n", sizeof(double));
    return 0;
}

//3.

#include <limits.h>
#include <stdio.h>

int main() {
    printf("Number of bits in an int: %d\n", (int)(sizeof(int) * CHAR_BIT));
    return 0;
}

//4.

#include <limits.h>
#include <stdio.h>

int main() {
    printf("Minimum value for char (signed): %d\n", SCHAR_MIN);
    printf("Maximum value for char (signed): %d\n", SCHAR_MAX);
    return 0;
}

//5.

#include <limits.h>
#include <stdio.h>

int main() {
    printf("Minimum value for short: %d\n", SHRT_MIN);
    printf("Maximum value for short: %d\n", SHRT_MAX);
    return 0;
}

//6.

#include <limits.h>
#include <stdio.h>

int main() {
    printf("Minimum value for int: %d\n", INT_MIN);
    printf("Maximum value for int: %d\n", INT_MAX);
    return 0;
}

//7.

#include <float.h>
#include <stdio.h>

int main() {
    printf("Minimum positive value for float: %e\n", FLT_MIN);
    printf("Maximum value for float: %e\n", FLT_MAX);
    return 0;
}

//8.

#include <stdio.h>

void print_bits(const void *ptr, size_t size) {
    const unsigned char *b = (const unsigned char *)ptr;
    for (size_t i = 0; i < size; i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (b[i] >> j) & 1);
        }
        printf(" ");
    }
    printf("\n");
}

int main() {
    char ch = 'D';
    printf("Bitwise representation of 'D': ");
    print_bits(&ch, sizeof(ch));
    return 0;
}
//9.

#include <stdio.h>

void print_bits(const void *ptr, size_t size) {
    const unsigned char *b = (const unsigned char *)ptr;
    for (size_t i = 0; i < size; i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (b[i] >> j) & 1);
        }
        printf(" ");
    }
    printf("\n");
}

int main() {
    short s = 255;
    printf("Bitwise representation of short 255: ");
    print_bits(&s, sizeof(s));
    return 0;
}


//10.

#include <stdio.h>

void print_bits(const void *ptr, size_t size) {
    const unsigned char *b = (const unsigned char *)ptr;
    for (size_t i = 0; i < size; i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (b[i] >> j) & 1);
        }
        printf(" ");
    }
    printf("\n");
}

int main() {
    float f = 5.625f;
    printf("Bitwise representation of float 5.625: ");
    print_bits(&f, sizeof(f));
    return 0;
}

