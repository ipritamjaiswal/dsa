/* Stack using Linked list */

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} Stack;

// Function prototypes
void push(Stack **top, int data);
void pop(Stack **top);
void display(Stack *top);
void free_stack(Stack **top);

int main(void) {
    Stack *top = NULL;

    int choice, data;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to push: ");
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    // Free stack
    free_stack(&top);
    return 0;
}

// Function definitions
void push(Stack **top, int data) {
    Stack *new_node = (Stack *)malloc(sizeof(Stack));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

void pop(Stack **top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    Stack *temp = *top;
    *top = (*top)->next;
    printf("Popped element: %d\n", temp->data);
    free(temp);
}

void display(Stack *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    Stack *temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void free_stack(Stack **top) {
    Stack *temp = *top;
    while (temp != NULL) {
        *top = (*top)->next;
        free(temp);
        temp = *top;
    }
}
