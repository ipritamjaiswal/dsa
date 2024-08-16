#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
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
    new_node->prev = NULL;
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
    new_node->prev = current;
}

void display_node(Node *head) {
    Node *current = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void delete_node(Node **head, int key) {
    Node *current = *head;
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // If the head node is the key
    if (current->data == key) {
        // If the list has only one node
        if (current->next == NULL) {
            *head = NULL;
            free(current);
            return;
        }
        // If the list has more than one node
        *head = current->next;
        (*head)->prev = NULL;
        free(current);
        return;
    }

    // Traverse to the key node
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    // If the key node is found
    if (current != NULL && current->data == key) {
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        if (current->prev != NULL) {
            current->prev->next = current->next;
        }
        free(current);
        return;
    }

    // If the key node is not found
    printf("Key not found\n");
}

void free_node(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}
