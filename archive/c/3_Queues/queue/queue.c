/* Array implementaion of queue */

#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

// Function prototypes
void enqueue(int);
int dequeue(void);
void display(void);

int main(void) {
    int choice, item;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                printf("The deleted element is %d\n", item);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function definitions

void enqueue(int item) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    // Add the element to the end of the queue
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = item;
}

int dequeue(void) {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;
    }
    // Remove the first element from the queue
    int item = queue[front];
    front++;
    return item;
}

void display(void) {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = rear; i >= front; i--) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}