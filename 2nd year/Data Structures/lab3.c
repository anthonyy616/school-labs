#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, char c) { s->data[++s->top] = c; }
char pop(Stack *s) { return s->data[s->top--]; }

// Problem 1: Reverse string
void reverseString(char *str) {
    Stack s; init(&s);
    for (int i = 0; str[i]; i++) push(&s, str[i]);
    for (int i = 0; !isEmpty(&s); i++) str[i] = pop(&s);
}

// Problem 2: Check balanced parentheses
int isBalanced(char *expr) {
    Stack s; init(&s);
    for (int i = 0; expr[i]; i++) {
        if (expr[i] == '(') push(&s, expr[i]);
        else if (expr[i] == ')') {
            if (isEmpty(&s)) return 0;
            pop(&s);
        }
    }
    return isEmpty(&s);
}

int main() {
    char str[] = "Anthony";
    reverseString(str);
    printf("Reversed: %s\n", str);  // ynohtnA

    printf("()(): %d\n", isBalanced("()()"));  // 1
    printf("((): %d\n", isBalanced("(()"));    // 0
    return 0;
}