#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

bool isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila esta vazia.\n");
        exit(1);
    }
    int item = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return item;
}

int countElements(struct Queue* queue) {
    int count = 0;
    struct Node* current = queue->front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

bool compareQueues(struct Queue* F1, struct Queue* F2) {
    int countF1 = countElements(F1);
    int countF2 = countElements(F2);

    return countF1 > countF2;
}

int main() {
    struct Queue* F1 = createQueue();
    struct Queue* F2 = createQueue();

    enqueue(F1, 1);
    enqueue(F1, 2);
    enqueue(F1, 3);

    enqueue(F2, 4);
    enqueue(F2, 5);

    if (compareQueues(F1, F2)) {
        printf("F1 tem mais elementos do que F2.\n");
    } else {
        printf("F2 tem mais elementos do que F1 ou eles tem a mesma quantidade de elementos.\n");
    }

    free(F1);
    free(F2);

    return 0;
}
