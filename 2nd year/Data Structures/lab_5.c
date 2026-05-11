#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack for operators
char stack[MAX];
int top = -1;

// Function prototypes
void push(char x);
char pop();
int isOperator(char ch);
int precedence(char ch);

int main() {
    char infix[MAX], postfix[MAX] = "", ch;
    int i = 0, j = 0;

    printf("Enter infix expression (e.g., (A+B)*C-D/E): ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0;  // remove newline

    // 2. Scan the infix expression from left to right

    while (infix[i] != '\0') {
        ch = infix[i];

        // 3. Skip whitespace
        if (isspace(ch)) {
            i++;
            continue;
        }
        // If operand (letter or digit) → directly to output
        else if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If opening parenthesis '(' → push to stack
        else if (ch == '(') {
            push(ch);
        }
        // If closing parenthesis ')'
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();  // discard the '('
        }
        // If operator +, -, *, /
        else if (isOperator(ch)) {
            while (top != -1 && stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }

        i++;
    }

    // 4. After end of input, pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    // 5. Print the final postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

// Push to stack
void push(char x) {
    if (top >= MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = x;
}

// Pop from stack
char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

// Check if character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Return precedence (higher number = higher precedence)
int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}