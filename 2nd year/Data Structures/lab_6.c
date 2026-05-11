#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked stack
typedef struct Node {
    int data;               // stores one bit (0 or 1)
    struct Node* next;
} Node;

// Function prototypes
void push(Node** top, int bit);
int pop(Node** top);
int isEmpty(Node* top);
void decimalToBinary(int decimal);

int main() {
    int num;
    
    printf("Enter a positive decimal integer: ");
    scanf("%d", &num);
    
    // Handle 0 as a special case
    if (num == 0) {
        printf("Binary representation: 0\n");a
        return 0;
    }
    
    if (num < 0) {
        printf("Please enter a positive integer only.\n");
        return 0;
    }
    
    printf("Binary representation: ");
    decimalToBinary(num);
    printf("\n");
    
    return 0;
}

// Push a new bit onto the stack
void push(Node** top, int bit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = bit;
    newNode->next = *top;
    *top = newNode;
}

// Pop a bit from the stack and return it
int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    Node* temp = *top;
    int bit = temp->data;
    *top = (*top)->next;
    free(temp);
    return bit;
}

// Check if stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

// Main conversion function
void decimalToBinary(int decimal) {
    Node* stack = NULL;    // Start with empty stack
    
    // Step 1: Repeatedly divide by 2 and push remainder (0 or 1)
    while (decimal > 0) {
        int remainder = decimal % 2;
        push(&stack, remainder);
        decimal = decimal / 2;
    }
    
    // Step 2: Now pop all bits from stack → this gives correct binary order
    while (!isEmpty(stack)) {
        printf("%d", pop(&stack));
    }
}