// Array Implementation of Lists

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int array[MAX_SIZE];
    int size;
} List;

// Function prototypes
void initList(List * list);
void insertElement(List * list, int element);
void displayList(List * list);
void deleteElement(List * list, int index);

int main(void) {
    List list;
    initList(&list);

    insertElement(&list, 10);
    insertElement(&list, 20);
    insertElement(&list, 30);

    printf("**** List Elements ****\n");
    displayList(&list);

    deleteElement(&list, 0);

    printf("**** List Elements After Deletion ****\n");
    displayList(&list);

    return 0;
}

// Function definitions

void initList(List * list) {
    list->size = 0;
}

void insertElement(List * list, int element) {
    if (list->size < MAX_SIZE) {
        list->array[list->size] = element;
        list->size++;
    }
    else {
        printf("List is full\n");
    }
}

void displayList(List * list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

void deleteElement(List * list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Invalid index\n");
    }
    else {
        for (int i = index; i < list->size - 1; i++) {
            list->array[i] = list->array[i + 1]; // Shift elements to the left
        }
        list->size--;
    }
}