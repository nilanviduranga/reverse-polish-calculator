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