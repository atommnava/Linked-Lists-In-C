#include "my-structure.h"

int main(void)
{
    Node root;
    root.x = 15;
    root.next = malloc(sizeof(Node));
    root.next -> x = -2;
    root.next -> next = NULL;

    Node *curr = &root;
    while (curr != NULL) {
        printf("%d\n", curr -> x);
        curr = curr -> next;
    }
    
    free(root.next);
}