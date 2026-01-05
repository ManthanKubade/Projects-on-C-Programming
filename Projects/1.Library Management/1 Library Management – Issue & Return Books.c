#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char name[30];
    int issued; // 0 = available, 1 = issued
};

int main() {
    struct Book b[3] = {
        {101, "C Programming", 0},
        {102, "Data Structures", 0},
        {103, "Operating System", 0}
    };

    int choice, id, i;

    do {
        printf("\n--- Library Management ---");
        printf("\n1. View Books\n2. Issue Book\n3. Return Book\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nID\tBook Name\tStatus\n");
            for (i = 0; i < 3; i++)
                printf("%d\t%s\t\t%s\n", b[i].id, b[i].name,
                       b[i].issued ? "Issued" : "Available");
            break;

        case 2:
            printf("Enter Book ID to issue: ");
            scanf("%d", &id);
            for (i = 0; i < 3; i++)
                if (b[i].id == id && b[i].issued == 0) {
                    b[i].issued = 1;
                    printf("Book Issued Successfully\n");
                }
            break;

        case 3:
            printf("Enter Book ID to return: ");
            scanf("%d", &id);
            for (i = 0; i < 3; i++)
                if (b[i].id == id && b[i].issued == 1) {
                    b[i].issued = 0;
                    printf("Book Returned Successfully\n");
                }
            break;
        }
    } while (choice != 4);

    return 0;
}
