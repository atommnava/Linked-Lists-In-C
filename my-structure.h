#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Node {
    int x;
    struct Node* next;
} Node;

void insertEnd(Node **root, int value);