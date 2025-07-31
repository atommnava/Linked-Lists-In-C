#include "my-structure-2.h"

void deallocate(Node **tail, Node **head)
{
    if (*tail == NULL) {
        return;
    }
    Node *curr = *tail;
    while (curr -> next != NULL) {
        curr = curr -> next;
        free(curr -> prev);
    }
    free(curr);
    *tail = NULL;
    *head = NULL;
}

void insert_beggining(Node **tail, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node -> x = value;
        new_node -> prev = NULL;
        new_node -> next = *tail;
        if (*tail != NULL) {
            (*tail) -> prev = new_node;
        }
        *tail = new_node;
    } else {
        exit(1);
        return;
    }
}

void insert_end(Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node -> x = value;
        new_node -> prev = *head;
        new_node -> next = NULL;
        if (*head != NULL) {
            (*head) -> next = new_node;
        }
        *head = new_node;
    } else {
        exit(1);
        return;
    }
}

void init(Node **tail, Node **head, int value)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(1);
        return;
    }
    new_node -> x = value;
    new_node -> prev = NULL;
    new_node -> next = NULL;
    *tail = new_node;
    *head = new_node;
}

void insert_after(Node *nodo, int value)
{
     Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(1);
        return;
    }
    new_node -> x = value;
    new_node -> prev = nodo;
    new_node -> next = nodo -> next;

    if (nodo -> next != NULL) {
        nodo -> next -> prev = new_node;
    }
    nodo -> next = new_node;
}

void remove_node(Node *node)
{
    if (node -> prev != NULL) {
        node -> prev -> next = node -> next;
    }
    if (node -> next != NULL) {
        node -> next -> prev = node -> prev;
    }
    free(node);
}

Node *find_node(Node *tail, int value)
{
    for (Node *curr = tail; curr != NULL; curr = curr -> next) {
        if (curr -> x == value) {
            return curr;
        }  
    }
    return NULL;
}

Node *find_node_recursive(Node *node, int value)
{
    if (node == NULL) {
        return NULL;
    }
    if (node -> x == value) {
        return node;
    }
    return find_node_recursive(node -> next, value);
}

void reverse_doubly_linked_list(Node **tail, Node **head)
{
    Node *curr = *tail;
    while (curr != NULL) {
        Node *next = curr -> next;
        curr -> next = curr -> prev;
        curr -> prev = next;
        curr = next;
    }
    Node *aux = *tail;
    *tail = *head;
    *head = aux;
}

int main(void)
{
    Node *tail = NULL;
    Node *head = NULL;

    init(&tail, &head, 7);
    insert_beggining(&tail, 3);
    insert_beggining(&tail, 1);
    Node *found = find_node_recursive(tail, 4);
    
    if (found == NULL) {
        printf("No Node was found!\n");
    }
    else  {
        printf("Value: %d Next: %p\n", found -> x, found -> next);
    }

    Node *curr = tail;
    while (curr != NULL) {
        printf("Node: %d\n", curr -> x);
        curr = curr -> next;
    }
    deallocate(&tail, &head);
    /*
    for (Node *curr = tail; curr != NULL; curr = curr -> next) {
        printf("Value: %d\n", curr -> x);
    }
    */
    return 0;
}