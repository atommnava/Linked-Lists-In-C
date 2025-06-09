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

void inserAfter(Node *node, int value)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(4);
    }
    newNode -> x = value;
    newNode -> next = node -> next;
    node -> next = newNode;
}

void inserSorted(Node **root, int value)
{
  //if (*root == NULL || (*root) -> x <= value) EQUIVALENT
  //                        2           1
  // 1 -> 2 -> 3 -> 4
    if (*root == NULL || (**root).x >= value ) {
        insertBeggining(root, value);
        return;
        // ONLY break; IT IS EQUIVALENT
    }
    Node *curr = *root;
    while (curr -> next != NULL) {
        if (curr -> next -> x >= value) {
            inserAfter(curr, value);
            return;
        }
        curr = curr -> next;
    }
    inserAfter(curr, value);
}
int main(void)
{
    Node *root = NULL;
    int first, second, third, fourth;
    printf("1st integer: ");
    scanf("%d", &first);

    printf("2snd integer: ");
    scanf("%d", &second);

    printf("3rd integer: ");
    scanf("%d", &third);

    printf("4th integer: ");
    scanf("%d", &fourth);

    inserSorted(&root, first);
    inserSorted(&root, second);
    inserSorted(&root, third);
    inserSorted(&root, fourth);
    for (Node *curr = root; curr != NULL; curr = curr -> next) {
        printf("%d\n", curr->x);
    }

    free(root);

    return 0;
}