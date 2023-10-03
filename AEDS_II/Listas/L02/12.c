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

void calculateStats(struct Queue* queue, int* maior, int* menor, double* media) {
    if (isEmpty(queue)) {
        printf("A fila esta vazia.\n");
        return;
    }

    int sum = 0;
    *maior = queue->front->data;
    *menor = queue->front->data;

    struct Node* current = queue->front;
    while (current != NULL) {
        int item = current->data;
        sum += item;
        if (item > *maior) {
            *maior = item;
        }
        if (item < *menor) {
            *menor = item;
        }
        current = current->next;
    }

    *media = (double)sum / queue->rear->data;
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 5);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 15);

    int maior, menor;
    double media;

    calculateStats(queue, &maior, &menor, &media);

    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
    printf("Media aritmetica: %.2f\n", media);

    free(queue);

    return 0;
}
