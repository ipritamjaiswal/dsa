/*  Implementation of Stack using array */

#include <stdio.h>

#define MAX 10

int stack[MAX];
int top = -1;

// Function prototype
void push(int);
void pop(void);
void display(void);

int main(void) {
    int choice, data;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
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

// Function implementation

void push(int data) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }

    top++;
    stack[top] = data;
}

void pop(void) {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }

    printf("Popped element: %d\n", stack[top]);
    top--;
}

void display(void) {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}