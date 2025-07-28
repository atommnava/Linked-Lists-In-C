#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Node {
    int x;
    struct Node* next;
    struct Node* prev;
} Node;

void deallocate(Node **tail, Node **head);
void insert_beggining(Node **tail, int value);