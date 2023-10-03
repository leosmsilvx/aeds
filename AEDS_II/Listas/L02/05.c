#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

bool isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

int countElements(struct Stack* stack) {
    return stack->top + 1;
}

bool compareStacks(struct Stack* P1, struct Stack* P2) {
    int countP1 = countElements(P1);
    int countP2 = countElements(P2);

    return countP1 > countP2;
}

int main() {
    struct Stack* P1 = createStack(100);
    struct Stack* P2 = createStack(100);

    push(P1, 1);
    push(P1, 2);
    push(P1, 3);

    push(P2, 4);
    push(P2, 5);

    if (compareStacks(P1, P2)) {
        printf("P1 tem mais elementos do que P2.\n");
    } else {
        printf("P2 tem mais elementos do que P1 ou eles tem a mesma quantidade de elementos.\n");
    }

    free(P1->array);
    free(P1);
    free(P2->array);
    free(P2);

    return 0;
}
