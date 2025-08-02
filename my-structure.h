#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Node {
    int x;
    struct Node* next;
} Node;

void insertBeggining(Node **root, int value);
void inserAfter(Node *node, int value);
void insertEnd(Node **root, int value);
void deallocate(Node **root);
void insertSorted(Node **root, int value);
void removeElement(Node **root, int value);
void reverse(Node **root);
int has_loops(Node *root);
int count(Node *root);
int count_recursive(Node *node);
void serialize(Node *root);
void deserialize(Node **root);