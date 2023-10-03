#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

bool isPalindrome(char* word) {
    int length = strlen(word);
    struct Stack* stack = createStack(length);

    for (int i = 0; i < length; i++) {
        push(stack, word[i]);
    }

    for (int i = 0; i < length; i++) {
        if (pop(stack) != word[i]) {
            free(stack->array);
            free(stack);
            return false;
        }
    }

    free(stack->array);
    free(stack);
    return true;
}

int main() {
    char word[100];
    printf("Digite uma palavra: ");
    scanf("%s", word);

    if (isPalindrome(word)) {
        printf("%s e um palindromo.\n", word);
    } else {
        printf("%s nao e um palindromo.\n", word);
    }

    return 0;
}
