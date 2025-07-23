#include "my-structure-2.h"

int main(void)
{
    Node *tail = malloc(sizeof(Node));
    if (tail == NULL) {
        return 1;
    }
    tail -> x = 1;
    tail -> prev = NULL;
    return 0;
}