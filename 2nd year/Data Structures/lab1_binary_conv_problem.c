#include <stdio.h>

void printBinary(int num) {
    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }
    
    // For negative numbers, we'll show 2's complement representation
    if (num < 0) {
        printf("Binary (2's complement): ");
        num = ~num + 1;  // Convert to positive equivalent
    } else {
        printf("Binary: ");
    }
    
    // Extract bits from MSB to LSB (32 bits)
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    int number;
    
    printf("Enter an integer: ");
    scanf("%d", &number);
    
    printf("Decimal: %d\n", number);
    printBinary(number);
    
    return 0;
}