/* Linked Queue */

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

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

Queue *create_queue();
void enqueue(Queue *queue, int);
void dequeue(Queue *queue);
void display(Queue *queue);
void free_queue(Queue *queue);

#endif // LINKED_QUEUE_H