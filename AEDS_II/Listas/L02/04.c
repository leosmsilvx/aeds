#include <stdio.h>
#include <stdlib.h>

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

int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

void reverseStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        return;
    }

    struct Stack* auxStack = createStack(stack->capacity);

    while (!isEmpty(stack)) {
        int item = pop(stack);
        push(auxStack, item);
    }

    while (!isEmpty(auxStack)) {
        int item = pop(auxStack);
        push(stack, item);
    }

    free(auxStack->array);
    free(auxStack);
}

int main() {
    struct Stack* stack = createStack(100);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    printf("Pilha original: ");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");

    reverseStack(stack);

    printf("Pilha invertida: ");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");

    free(stack->array);
    free(stack);

    return 0;
}
