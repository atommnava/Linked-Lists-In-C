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
void insert_end(Node **head, int value);
void init(Node **tail, Node **head, int value);
void insert_after(Node *nodo, int value);
void remove_node(Node *node);
Node *find_node(Node *tail, int value);
Node *find_node_recursive(Node *node, int value);
void reverse_doubly_linked_list(Node **tail, Node **head);