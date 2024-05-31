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

    push(s, result);
}

int main() {
    Stack stack;
    initializeStack(&stack);

    char input[500];

    printf("\n\t\t\t\t\t    +++++++++++++++++++++++++++++++++");
    printf("\n\t\t\t\t\t    +  REVERSE POLISH CALCULATOR    +");
    printf("\n\t\t\t\t\t    +++++++++++++++++++++++++++++++++");
    printf("\n\nEnter RPN (Reverse Polish notation) expression: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " \n");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atof(token));
        } else if (strlen(token) == 1 && strchr("+-*/", token[0])) {
            performOperation(&stack, token[0]);
        } else if (strcmp(token, "=") == 0) {
            printf("Result: %.2f\n", pop(&stack));
        } else {
            printf("Invalid input: %s\n", token);
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, " \n");
    }
    if (!isEmpty(&stack)) {
        printf("Warning: There are leftover elements in the stack.\n");
    }
    
    return 0;
}