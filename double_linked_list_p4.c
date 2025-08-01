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

int main(void)
{
    Node *tail = NULL;
    Node *head = NULL;

    init(&tail, &head, 7);
    insert_end(&head, 3);
    insert_end(&head, 1);  

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