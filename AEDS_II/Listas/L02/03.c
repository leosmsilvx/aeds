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

int findMax(struct Stack* stack) {
    int max = stack->array[0];
    for (int i = 1; i <= stack->top; i++) {
        if (stack->array[i] > max) {
            max = stack->array[i];
        }
    }
    return max;
}

int findMin(struct Stack* stack) {
    int min = stack->array[0];
    for (int i = 1; i <= stack->top; i++) {
        if (stack->array[i] < min) {
            min = stack->array[i];
        }
    }
    return min;
}

double calculateAverage(struct Stack* stack) {
    if (stack->top == -1) {
        return 0.0;
    }

    int sum = 0;
    for (int i = 0; i <= stack->top; i++) {
        sum += stack->array[i];
    }

    return (double)sum / (stack->top + 1);
}

int main() {
    struct Stack* stack = createStack(100);

    push(stack, 10);
    push(stack, 5);
    push(stack, 20);
    push(stack, 30);
    push(stack, 15);

    int max = findMax(stack);
    int min = findMin(stack);
    double average = calculateAverage(stack);

    printf("Maior elemento: %d\n", max);
    printf("Menor elemento: %d\n", min);
    printf("Media aritmetica: %.2f\n", average);

    free(stack->array);
    free(stack);

    return 0;
}
