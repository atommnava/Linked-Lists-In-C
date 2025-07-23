#include "my-structure-2.h"

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
    tail -> next -> next -> prev = tail;
    tail -> next -> next -> next = NULL;

    return 0;
}