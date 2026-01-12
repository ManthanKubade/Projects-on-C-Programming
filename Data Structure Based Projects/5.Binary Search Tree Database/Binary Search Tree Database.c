#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    struct Node *left, *right;
};

struct Node* create(int id) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->id = id;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int id) {
    if (!root) return create(id);
    if (id < root->id)
        root->left = insert(root->left, id);
    else
        root->right = insert(root->right, id);
    return root;
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->id);
    inorder(root->right);
}

int search(struct Node* root, int id) {
    if (!root) return 0;
    if (root->id == id) return 1;
    if (id < root->id) return search(root->left, id);
    return search(root->right, id);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    printf("Database Records: ");
    inorder(root);

    int key = 40;
    if (search(root, key))
        printf("\nRecord %d found", key);
    else
        printf("\nRecord not found");

    return 0;
}
