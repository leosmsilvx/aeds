#include <stdio.h>
#include <stdlib.h>

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

int isEmpty(struct Queue* queue) {
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
        printf("A fila está vazia.\n");
        exit(1);
    }
    int item = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return item;
}

void mergeQueues(struct Queue* F1, struct Queue* F2, struct Queue* F3) {
    while (!isEmpty(F1) && !isEmpty(F2)) {
        int valueF1 = F1->front->data;
        int valueF2 = F2->front->data;

        if (valueF1 < valueF2) {
            enqueue(F3, valueF1);
            dequeue(F1);
        } else {
            enqueue(F3, valueF2);
            dequeue(F2);
        }
    }

    while (!isEmpty(F1)) {
        enqueue(F3, dequeue(F1));
    }

    while (!isEmpty(F2)) {
        enqueue(F3, dequeue(F2));
    }
}

void displayQueue(struct Queue* queue) {
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue* F1 = createQueue();
    struct Queue* F2 = createQueue();
    struct Queue* F3 = createQueue();

    enqueue(F1, 1);
    enqueue(F1, 3);
    enqueue(F1, 5);

    enqueue(F2, 2);
    enqueue(F2, 4);
    enqueue(F2, 6);

    printf("F1: ");
    displayQueue(F1);

    printf("F2: ");
    displayQueue(F2);

    mergeQueues(F1, F2, F3);

    printf("F3 (merge de F1 e F2 em ordem crescente): ");
    displayQueue(F3);

    free(F1);
    free(F2);
    free(F3);

    return 0;
}
