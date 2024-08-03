/* Array Implimentation of Dequeue */

#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

// Function Prototypes
void enqueue_front(int);
void enqueue_rear(int);
void dequeue_front();
void dequeue_rear();
void display();

int main() {
    int choice, data;

    do {
        printf("\n1. Enqueue Front\n2. Enqueue Rear\n3. Dequeue Front\n4. Dequeue Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue_front(data);
                break;
            case 2:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue_rear(data);
                break;
            case 3:
                dequeue_front();
                break;
            case 4:
                dequeue_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return  0;
}

// Function definitions

void enqueue_front(int data) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    queue[front] = data;
}

void enqueue_rear(int data) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = data;
}

void dequeue_front() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
    printf("Dequeued element: %d\n", queue[front]);
}

void dequeue_rear() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are:\n");
    if (front <= rear) {
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}