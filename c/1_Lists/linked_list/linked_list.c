// Implementation of a linked list

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

    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);
    printf("*** List After Insertion ***\n");
    display_node(head);

    delete_node(&head, 3);
    printf("*** List After Deletion ***\n");
    display_node(head);

    // Free memory allocated
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
    
    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Traverse to the end of the list
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Insert the new node at the end of the list
    current->next = new_node;
}

void display_node(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void delete_node(Node **head, int key) {
    if (*head == NULL) {
        return;
    }

    Node *current = *head;
    Node * prev = NULL;
    // If the head node is to be deleted
    if (current->data == key) {
        *head = current->next;
        free(current);
        return;
    }

    // Traverse to the node to find the node to be deleted
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return; // If the node is not found, return
    prev->next = current->next;
    free(current);
}

void free_node(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}