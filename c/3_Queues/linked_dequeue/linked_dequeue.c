/* Linked List implementation of dequeue */

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

// Dequeue structure
typedef struct dequeue {
    Node *front;
    Node *rear;
} Dequeue;

// Function prototypes
Dequeue* createDequeue();
Node* createNode(int data);
void enqueueFront(Dequeue *dq, int data);
void enqueueRear(Dequeue *dq, int data);
int dequeueFront(Dequeue *dq);
int dequeueRear(Dequeue *dq);
void display(Dequeue *dq);
void freeDequeue(Dequeue *dq);

int main(void) {
    Dequeue *dq = createDequeue();
    enqueueFront(dq, 10);
    enqueueFront(dq, 20);
    enqueueRear(dq, 30);
    enqueueRear(dq, 40);
    enqueueFront(dq, 50);

    printf("Dequeue after enqueueing: \n");
    display(dq);

    printf("Dequeued front: %d\n", dequeueFront(dq));
    printf("Dequeued rear: %d\n", dequeueRear(dq));

    printf("Dequeue after dequeueing: \n");
    display(dq);

    freeDequeue(dq);
    return 0;
}

// Function definitions

Dequeue* createDequeue() {
    Dequeue *dq = (Dequeue*) malloc(sizeof(Dequeue));
    if (dq == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    dq->front = NULL;
    dq->rear = NULL;
    return dq;
}

Node* createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void enqueueFront(Dequeue *dq, int data) {
    Node *newNode = createNode(data);

    if (dq->front == NULL) {
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
}

void enqueueRear(Dequeue *dq, int data) {
    Node *newNode = createNode(data);

    if (dq->rear == NULL) {
        dq->front = newNode;
        dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}

int dequeueFront(Dequeue *dq) {
    if (dq->front == NULL) {
        printf("Queue underflow.\n");
        return -1;
    }

    Node *temp = dq->front;
    int data = temp->data;

    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    } else {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }

    free(temp);
    return data;
}

int dequeueRear(Dequeue *dq) {
    if (dq->rear == NULL) {
        printf("Queue underflow.\n");
        return -1;
    }

    Node *temp = dq->rear;
    int data = temp->data;

    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    } else {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }

    free(temp);
    return data;
}

void display(Dequeue *dq) {
    if (dq->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node *temp = dq->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeDequeue(Dequeue *dq) {
    Node *current = dq->front;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(dq);
}