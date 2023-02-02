//
// Created by Lenovo on 2022. 03. 22..
//

#ifndef PARALLEL7GY_LINKEDLIST_H
#define PARALLEL7GY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void printList(struct Node *n) {
    printf("Printing linked list elements: ");
    while (n != NULL) { ;
        printf(" %d ", n->data);
        n = n->next;
    }
    printf("\n");
}

#endif //PARALLEL7GY_LINKEDLIST_H
