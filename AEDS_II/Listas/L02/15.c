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
        printf("A fila esta vazia.\n");
        exit(1);
    }
    int item = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return item;
}

void concatenateQueues(struct Queue* F1, struct Queue* F2) {
    while (!isEmpty(F2)) {
        int item = dequeue(F2);
        enqueue(F1, item);
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

    enqueue(F1, 1);
    enqueue(F1, 2);

    enqueue(F2, 3);
    enqueue(F2, 4);

    printf("F1 antes da concatenacao: ");
    displayQueue(F1);

    printf("F2 antes da concatenacao: ");
    displayQueue(F2);

    concatenateQueues(F1, F2);

    printf("F1 apos a concatenacao: ");
    displayQueue(F1);

    printf("F2 apos a concatenacao: ");
    displayQueue(F2);

    free(F1);
    free(F2);

    return 0;
}
