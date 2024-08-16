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

    if (*head == NULL) {
        *head = new_node;
        (*head)->next = *head;
        return;
    }

    // Traverse to the last element
    Node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = new_node;
    new_node->next = *head;
}

void display_node(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void delete_node(Node **head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *current = *head, *prev = NULL;

    // Check if the head node contains the key
    if ((*head)->data == key) {
        // Update the head pointer
        if (current == *head) { // Only one node in the list
            free(*head);
            *head = NULL;
            return;
        }

        // Traverse to end of list
        while (current->next != *head) {
            current = current->next;
        }
        current->next = (*head)->next;
        free(*head);
        *head = current->next;
        return;
    }

    // Traverse to the node before the key
    prev = *head;
    current = (*head)->next;
    while (current != *head && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If the key is not found
    if (current == *head) {
        printf("Key not found\n");
        return;
    }

    // Delete the node
    prev->next = current->next;
    free(current);
}


void free_node(Node *head) {
    if (head == NULL) {
        return;
    }

    Node *current = head;
    while (current->next != head) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(current);
}