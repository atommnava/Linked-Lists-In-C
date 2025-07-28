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
        (*tail) -> prev = new_node;
        *tail = new_node;
    } else {
        exit(1);
        return;
    }
}

int main(void)
{
    Node *tail = malloc(sizeof(Node));
    if (tail == NULL) {
        return 1;
    }
    tail -> x = 1;
    tail -> prev = NULL;
    tail -> next = malloc(sizeof(Node));
    if (tail -> next == NULL) {
        return 2;
    }
    tail -> next -> x = 3;
    tail -> next -> prev = tail;
    tail -> next -> next = malloc(sizeof(Node));
    if (tail -> next -> next == NULL) {
        return 3;
    }
    tail -> next -> next -> x = 7;
    tail -> next -> next -> prev = tail -> next;
    tail -> next -> next -> next = NULL;
    Node *head = tail -> next -> next;

    Node *curr = tail;
    while (curr != NULL) {
        printf("Value: %d\n", curr -> x);
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