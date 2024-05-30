#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {    // Stack structure
    double items[MAX_STACK_SIZE];
    int top;
} Stack;

void initializeStack(Stack *s) {    // Initialize stack
    s->top = -1;
}

int isEmpty(Stack *s) {     // Check if stack is empty
    return s->top == -1;
}

int isFull(Stack *s) {      // Check if stack is full
    return s->top == MAX_STACK_SIZE - 1;
}

void push(Stack *s, double value) {     // Push element onto stack
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++s->top] = value;
}

double pop(Stack *s) {      // Pop element from stack
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top--];
}

void performOperation(Stack *s, char operator) {    // operators
    double N1, N2, result;

    N2 = pop(s);  // Pop the second operand first
    N1 = pop(s);  // Then pop the first operand

    switch (operator) {
        case '+':
            result = N1 + N2;
            break;
        case '-':
            result = N1 - N2;
            break;
        case '*':
            result = N1 * N2;
            break;
        case '/':
            if (N2 == 0) {
                printf("Division by zero error\n");
                exit(EXIT_FAILURE);
            }
            result = N1 / N2;
            break;
        default:
            printf("Invalid Operator\n");
            exit(EXIT_FAILURE);
    }

    push(s, result);
}