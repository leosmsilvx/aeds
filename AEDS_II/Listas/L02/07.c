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

int countOddElements(struct Stack* stack) {
    int count = 0;

    for (int i = 0; i <= stack->top; i++) {
        if (stack->array[i] % 2 != 0) {
            count++;
        }
    }

    return count;
}

int main() {
    struct Stack* stack = createStack(100);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    int oddCount = countOddElements(stack);

    printf("Numero de elementos impares na pilha: %d\n", oddCount);

    free(stack->array);
    free(stack);

    return 0;
}
