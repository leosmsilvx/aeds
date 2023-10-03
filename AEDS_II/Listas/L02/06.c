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

void reverseQueue(struct Queue* queue) {
    struct Stack {
        int data;
        struct Stack* next;
    }* top = NULL;

    while (!isEmpty(queue)) {
        int item = dequeue(queue);

        struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
        newNode->data = item;
        newNode->next = top;
        top = newNode;
    }

    while (top != NULL) {
        int item = top->data;
        enqueue(queue, item);

        struct Stack* temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {
    struct Queue* queue = createQueue();
    
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("Fila original: ");
    while (!isEmpty(queue)) {
        printf("%d ", dequeue(queue));
    }
    printf("\n");

    reverseQueue(queue);

    printf("Fila invertida: ");
    while (!isEmpty(queue)) {
        printf("%d ", dequeue(queue));
    }
    printf("\n");

    free(queue);

    return 0;
}
