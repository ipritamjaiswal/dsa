/* 
    Circular Linked List implementation in C programming language
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

// Function prototypes
Node* create_node(int data);
void insert_node(Node **head, int data);
void display_node(Node *head);
void delete_node(Node **head, int key);
void free_node(Node *head);

int main(void) {
    Node *head = NULL;

    insert_node(&head, 10);
    insert_node(&head, 20);
    insert_node(&head, 30);
    insert_node(&head, 40);
    insert_node(&head, 50);

    printf("*** List After Insertion ***\n");
    display_node(head);

    delete_node(&head, 20);
    printf("*** List After Deletion ***\n");
    display_node(head);
    free_node(head);
    return 0;
}

// Function definitions

Node* create_node(int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void insert_node(Node **head, int data) {
    Node *new_node = create_node(data);

    
}