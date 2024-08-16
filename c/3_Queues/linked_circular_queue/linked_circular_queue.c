/* Linked list implementaion of circular queue */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

// Function prototypes
int isEmpty(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
void display(Queue *q);
void freeQueue(Queue *q);

int main() {
    Queue q;
    // Initialize queue
    q.front = NULL;
    q.rear = NULL;

    // Enqueue elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    // Display queue
    display(&q);

    // Dequeue elements
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));

    // Display queue
    display(&q);

    // Free memory
    freeQueue(&q);
    return 0;
}

// Function definitions
int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }

    q->rear = newNode;
    q->rear->next = q->front;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    Node *temp = q->front;
    int data = temp->data;

    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = q->front->next;
        q->rear->next = q->front;
    }

    free(temp);
    return data;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    Node *current = q->front;
    while (current != q->rear) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("%d\n", current->data);
}

void freeQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    Node *current = q->front;
    while (current != q->rear) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    free(current);
    q->front = NULL;
    q->rear = NULL;
}