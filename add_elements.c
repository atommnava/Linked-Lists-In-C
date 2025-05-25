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
    
    free(root);

    return 0;
}