#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HASHTABLESIZE 20
#define BTREEMAX 3
#define BTREEMIN 2

struct Bucket {
    int key, value;
};
struct Node{
    int count;
    int value[BTREEMAX+1];
    struct Node* next[BTREEMAX+1];
};

struct Bucket* hashTableArray[HASHTABLESIZE];
struct Node *root = NULL;

int getHashCode(int key) {
    return key % HASHTABLESIZE;
}
void insertHashTable(int key, int value) {
    struct Bucket *temp = (struct Bucket*) malloc(sizeof(struct Bucket));
    temp->value = value;
    temp->key = key;

    int index = getHashCode(temp->key);
    while(hashTableArray[index] && hashTableArray[index]->key != -1) {
        index = index+1;
        index = index % HASHTABLESIZE;
    }

    hashTableArray[index] = temp;
}

void searchHashTable(int key) {
    int index = getHashCode(key);

    while(hashTableArray[index]) {
        if(hashTableArray[index]->key == key){
            printf("Key: %d, found with value: %d \n", key, hashTableArray[index]->value);
        }
        index = index + 1;
        index = index % HASHTABLESIZE;
    }
}

void displayHashTable() {
    int i;
    for(i=0; i<HASHTABLESIZE; i++) {
        if(hashTableArray[i])
            printf("Key: %d, Value: %d \n",hashTableArray[i]->key,hashTableArray[i]->value);
    }

    printf("\n");
}

struct Node* newNode(int data, struct Node *child){
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));

    temp->count = 1;
    temp->value[1] = data;
    temp->next[0] = root;
    temp->next[1] = child;

    return temp;
}

struct Node* insertTreeNode(int value, int position, struct Node *n, struct Node *child){
    int count = n->count;

    while (count > position) {
        n->value[count+1] = n->value[count];
        n->next[count+1] = n->next[count];
        count--;
    }

    n->value[count+1] = value;
    n->next[count+1] = child;
    n->count++;
}

void adjustNode(int value, int *prevVal, int position, struct Node *n, struct Node *child, struct Node **nn) {
    int med;

    if (position > BTREEMIN) med = BTREEMIN+1;
    else med = BTREEMIN;

    *nn = (struct Node *)malloc(sizeof(struct Node));
    int temp = med + 1;

    while (temp <= BTREEMAX) {
        (*nn)->value[temp-med] = n->value[temp];
        (*nn)->next[temp-med] = n->next[temp];
        temp++;
    }

    n->count = med;
    (*nn)->count = BTREEMAX-med;

    if (position <= BTREEMIN) insertTreeNode(value, position, n, child);
    else insertTreeNode(value, position - med, *nn, child);

    *prevVal = n->value[n->count];
    (*nn)->next[0] = n->next[n->count];

    n->count--;
}

int setNodeValue(int value, int *prevVal, struct Node *n, struct Node **child) {
    int pos;

    if (n == NULL) {
        *prevVal = value;
        *child = NULL;
        return 1;
    }

    if (value < n->value[1]){
        pos=0;
    } else {
        for (pos = n->count; value<n->value[pos] && pos>1; pos--);

        if (value == n->value[pos]) {
            printf("Duplicate values not allowed\n");
            return 0;
        }
    }

    if (setNodeValue(value, prevVal, n->next[pos], child)) {
        if (n->count < BTREEMAX){
            insertTreeNode(*prevVal, pos, n, *child);
        } else {
            adjustNode(*prevVal, prevVal, pos, n, *child, child);
            return 1;
        }
    }

    return 0;
}

void insertBTree(int value) {
    int temp;
    struct Node *child;

    int isSetValue = setNodeValue(value, &temp, root, &child);
    if (isSetValue)
        root = newNode(temp, child);
}

void searchBTree(int value, int *position, struct Node *n) {
    if (n == NULL) return;

    if (value < n->value[1])
        *position = 0;
    else {
        for (*position = n->count;
             (value < n->value[*position] && *position > 1); (*position)--)
            ;
        if (value == n->value[*position]) {
            printf("Element: %d found", value);
            return;
        }
    }

    searchBTree(value, position, n->next[*position]);
    return;
}

void displayBTree(struct Node *n) {
    if (n == NULL) return;

    int i;
    for (i=0; i<n->count; i++) {
        displayBTree(n->next[i]);
        printf("%d, ", n->value[i+1]);
    }

    displayBTree(n->next[i]);
}

int main() {
    struct Bucket *temp = NULL;
    int tempAdd;
    int limit = 1000;
    srand(time(NULL));      // Pseudo-random number generator

    // Inserting values in hash table is faster than B-Tree in average case, as Hash Table will insert in O(1)
    // But in worst case where hash key already been used, Hash Table will look for next bucket to insert
    // In such cases, Hash Table can take longer than O(1)

    // Inserting 10 random values in our Hash Table
    int i;
    for(i=1; i<=10; i++){
        insertHashTable(i, rand()%limit);       // O(1)
    }
    // Since we are adding random value, so, we need one known value to search and delete from table.
    // Therefore, we are inserting value: 169, with the hash key: 11
    insertHashTable(11, 169);       // O(1)

    // B-tree will insert in O(log(n)) in every case, average or worst.
    // So B-Tree is better if we are inserting large data and/or we have a lot of repetition.
    // Cause Hash Table will get slower if values get repeated.

    // Inserting 10 random values in B-Tree
    for(i=0; i<10; i++){
        insertBTree(rand()%limit);       // O(log(n))
    }
    // Since we are adding random value, so, we need one known value to search and delete from B-Tree.
    // Therefore, we are inserting value: 112
    insertBTree(112);       // O(log(n))


    // Displaying a complete Hash Table is like printing an array.
    // So this operation will take O(n) time, where 'n' will be the length of the Hash Table.
    printf("<=== Hash Table Display ===> \n");
    displayHashTable();       // O(n)

    // Time Complexity: O(log(n))
    printf("<=== B-Tree Display ===> \n");
    displayBTree(root);       // O(log(n))

    // Search in Hash Table also take O(1)
    // Which makes Hash Table a lot faster than any other data structure.

    // Search from Hash Table
    printf("\n\n<=== Hash Table Search ===> \n");
    searchHashTable(11);                // O(1)

    // Searching in B-Tree is slower than hash table, as it takes O(log(n))
    // But B-Tree is better if we are searching in a range.
    // As Hash Table does not search values in this way.
    // So Hash Table has to search each element in a range one by one. which makes it slower than B-Tree in range search

    // Search from B-Tree
    printf("\n<=== B-Tree Search ===> \n");
    searchBTree(112, &tempAdd, root);   // O(log(n))

    /*
        Hash Table:
        1. Hash Table are faster for insertion and searching data.
        2. But to store large data in Hash Table we need more memory, so Hash Table are not good if we have limited memory resources
        3. Hash Table only works good as long as we know the size of hash table in advance. Because increasing size will cause rehashing the complete table
            which is too expensive in terms of performance.

        B-Tree:
        1. B-Tree are slower than hash table in single search case, but in range search b-tree are a lot faster.
        2. B-Tree does not need to take extra memory as hash table, as it will only take memory as much as it need.
        3. B-Tree can provide us the sorted values just by a pre-order/post-order traversal, which gives an extra credit to b-tree
    */

    /*
        Summary:
        1. Hash Table should be use where out data is limited and we know the size of data in advance.
        2. B-Tree should be use where our memory resources are limited and we have to search data in ranges at large scale.
    */
}
