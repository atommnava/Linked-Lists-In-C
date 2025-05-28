#include "my-structure.h"

void insertEnd(Node **root, int value)
{
    Node *newNode = malloc(sizeof(Node));
    Node *curr = *root;
    if (newNode == NULL) exit(1);
    newNode -> next = NULL;
    newNode -> x = value; 

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    while (curr -> next != NULL) {
        curr = curr -> next;
    }
    curr -> next = newNode;
}

void deallocate(Node **root)
{
    Node *curr = *root;
    Node *aux;
    while (curr != NULL) {
        aux = curr;
        curr = curr -> next;
        free(aux);
    }
    /* RECURSIVE MANNER
    void recursiveDeallocate(Node **node) {
        if (*node == NULL) return;
        deallocate(*(&node) -> next);
        free(*node);
        *node = NULL;
    */
    *root = NULL;
    printf("DEALLOCATION SUCCESSFULLY..!");
}

int main(void)
{
    Node *root = NULL;
    int first, second, input_valid;
    printf("1st integer: ");
    scanf("%d", &first);

    insertEnd(&root, first);
    insertEnd(&root, 6);
    insertEnd(&root, 8);
    for (Node *curr = root; curr != NULL; curr = curr -> next) {
        printf("%d\n", curr->x);
    }
    deallocate(&root);
    
    return 0;
}