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