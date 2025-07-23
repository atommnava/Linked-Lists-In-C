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

void insertSorted(Node **root, int value)
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

void removeElement(Node **root, int value)
{
    Node *curr = *root;
    Node *to_remove = NULL;
    if (*root == NULL) {
        return;
    }

    if ((*root) -> x == value) {
        to_remove = *root;
        *root = (*root) -> next;
        free(to_remove); 
        return;
    }

    while (curr -> next != NULL) {
        if (curr -> next -> x == value) {
            to_remove = curr -> next;
            curr -> next = curr -> next -> next;
            free(to_remove);
            return;
        }
        curr = curr -> next;
    }
}

void reverse(Node **root) {
    Node *prev = NULL;
    Node *curr = *root;
    while (curr != NULL) {
        Node *next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    *root = prev;
}

int has_loops(Node *root)
{
    Node *slow = root;
    Node *fast = root;


    while (slow != NULL && fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

int count(Node *root)
{
    Node *curr = root;
    int c = 0;
    while (curr != NULL) {
        curr = curr -> next;
        c++;
    }
    return c;
}

int count_recursive(Node *node)
{
    if (node == NULL) {
        return 0;
    }
    return 1 + count_recursive(node -> next);
}

int main(void)
{
    system("clear");
    Node *root = NULL;
    int first, second, third, fourth, fifth;
    printf("1st integer: ");
    scanf("%d", &first);

    printf("2nd integer: ");
    scanf("%d", &second);

    printf("3rd integer: ");
    scanf("%d", &third);

    printf("4th integer: ");
    scanf("%d", &fourth);

    printf("5th integer: ");
    scanf("%d", &fifth);

    insertSorted(&root, first);
    insertSorted(&root, second);
    insertSorted(&root, third);
    insertSorted(&root, fourth);
    insertSorted(&root, fifth);
    //removeElement(&root, first);
    //root -> next -> next -> next -> next -> next = root -> next;
    reverse(&root);
    if (has_loops(root) == 1) {
        printf("Linked List has a LOOP...\n");
        return 1;
    }
    Node *curr = root;
    while(curr != NULL) {
        printf("%d\n", curr->x);
        curr = curr -> next;
    }
    printf("Linked List has %d elements withouth Recursiveness...\n", count(root));
    printf("Linked List has %d elements with Recursiveness...\n", count_recursive(root));
    /*
    for (Node *curr = root; curr != NULL; curr = curr -> next) {
        printf("%d\n", curr->x);
    }
    */
    deallocate(&root);

    return 0;
}