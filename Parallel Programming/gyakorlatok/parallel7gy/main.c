#include <stdio.h>
#include <stdlib.h>
#include "dynamicarray.h"
#include "linkedlist.h"
#include "queue.h"

int main() {
    printf("--------------------- Dynamic Array ------------------------\n");

    // Dynamic Array
    Array a;
    int i;

    initArray(&a, 5);  // initially 5 elements
    for (i = 0; i <= 110; i++) {
        insertArray(&a, i);  // automatically resizes as necessary
    }
    printf("0th element: %d\n", a.array[0]);  // print 10th element
    printf("9th element: %d\n", a.array[9]);  // print 10th element
    printf("105th element: %d\n", a.array[105]);  // print 105th element
    printf("Number of elements: %d\n", a.used);  // print number of elements
    freeArray(&a); // free memory

    printf("--------------------- Linked List ---------------------\n");

    // Linked List
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // allocate 3 nodes in the heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second

    second->data = 2; // assign data to second node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = NULL;

    printList(head);

    printf("--------------------- Queue ---------------------\n");

    // Queue
    struct Queue *queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n", dequeue(queue));

    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    return 0;
}
