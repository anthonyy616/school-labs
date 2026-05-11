#include <stdio.h>
#define SIZE 4

char q[SIZE];
int front = 0, rear = 0;

void enqueue(char c) {
    if (rear == SIZE) {
        printf("FULL\n");
        return;
    }
    q[rear++] = c;
}

void dequeue() {
    if (front == rear) {
        printf("EMPTY\n");
        return;
    }
    front++;
}

void printq() {
    printf("[");
    for (int i = front; i < rear; i++) printf("%c ", q[i]);
    printf("]\n");
}

int main() {
    char op, c;
    while (1) {
        printf("e X  (enqueue)\nd    (dequeue)\np    (print)\nx    (exit)\n> ");
        scanf(" %c", &op);
        if (op == 'e') { scanf(" %c", &c); enqueue(c); }
        else if (op == 'd') dequeue();
        else if (op == 'p') printq();
        else if (op == 'x') break;
    }
}
