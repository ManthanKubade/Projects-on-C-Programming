#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    struct Book *left, *right;
};

// Create new book node
struct Book* createBook(int id, char title[], char author[]) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->left = newBook->right = NULL;
    return newBook;
}

// Insert book into BST
struct Book* insert(struct Book* root, int id, char title[], char author[]) {
    if (root == NULL)
        return createBook(id, title, author);

    if (id < root->id)
        root->left = insert(root->left, id, title, author);
    else if (id > root->id)
        root->right = insert(root->right, id, title, author);

    return root;
}

// Search book
struct Book* search(struct Book* root, int id) {
    if (root == NULL || root->id == id)
        return root;

    if (id < root->id)
        return search(root->left, id);
    else
        return search(root->right, id);
}

// Find minimum node
struct Book* findMin(struct Book* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete book
struct Book* deleteBook(struct Book* root, int id) {
    if (root == NULL) return root;

    if (id < root->id)
        root->left = deleteBook(root->left, id);
    else if (id > root->id)
        root->right = deleteBook(root->right, id);
    else {
        if (root->left == NULL) {
            struct Book* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            struct Book* temp = root->left;
            free(root);
            return temp;
        }

        struct Book* temp = findMin(root->right);
        root->id = temp->id;
        strcpy(root->title, temp->title);
        strcpy(root->author, temp->author);
        root->right = deleteBook(root->right, temp->id);
    }
    return root;
}

// Display books (Inorder Traversal)
void display(struct Book* root) {
    if (root != NULL) {
        display(root->left);
        printf("ID: %d | Title: %s | Author: %s\n", root->id, root->title, root->author);
        display(root->right);
    }
}

int main() {
    struct Book* root = NULL;
    int choice, id;
    char title[50], author[50];

    while (1) {
        printf("\n--- Library Search Engine ---\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Delete Book\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                printf("Enter Title: ");
                scanf(" %[^\n]", title);
                printf("Enter Author: ");
                scanf(" %[^\n]", author);
                root = insert(root, id, title, author);
                printf("Book Added Successfully!\n");
                break;

            case 2:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                struct Book* found = search(root, id);
                if (found)
                    printf("Found: %s by %s\n", found->title, found->author);
                else
                    printf("Book not found!\n");
                break;

            case 3:
                printf("Enter Book ID to delete: ");
                scanf("%d", &id);
                root = deleteBook(root, id);
                printf("Book Deleted Successfully!\n");
                break;

            case 4:
                printf("\nLibrary Books List:\n");
                display(root);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
