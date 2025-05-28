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

void insertBeggining(Node **root, int value)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) exit(3);
    newNode -> x = value;
    newNode -> next = *root;
    *root = newNode;
}

int main(void)
{
    Node *root = NULL;
    int first, second, input_valid;
    printf("1st integer: ");
    scanf("%d", &first);

    printf("2snd integer: ");
    scanf("%d", &second);

    insertBeggining(&root, first);
    insertBeggining(&root, second);
    
    for (Node *curr = root; curr != NULL; curr = curr -> next) {
        printf("%d\n", curr->x);
    }
    
    free(root);

    return 0;
}