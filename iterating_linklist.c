#include "my-structure.h"

int main(void)
{
    Node root;
    root.x = 15;
    root.next = malloc(sizeof(Node));
    root.next -> x = -2;
    root.next -> next = malloc(sizeof(Node));
    root.next -> next -> x = 22;
    root.next -> next -> next = NULL;

    Node *curr = &root;
    while (curr != NULL) {
        printf("%d\n", curr -> x);
        curr = curr -> next;
    }
    /*  EQUIVALENT, NOT RECOMENDED! :)
        for (Node *curr = &root; curr != NULL; curr -> curr -> next) {
            printf("%d\n", curr -> x);
        }
    */
    free(root.next -> next);
    free(root.next);
}