#include <stdio.h>
#include <string.h>

struct Customer {
    int id;
    char name[30];
    char email[40];
    char phone[15];
};

struct Customer c[100];
int count = 0;

void addCustomer() {
    printf("\nEnter Customer ID: ");
    scanf("%d", &c[count].id);

    printf("Enter Name: ");
    scanf("%s", c[count].name);

    printf("Enter Email: ");
    scanf("%s", c[count].email);

    printf("Enter Phone: ");
    scanf("%s", c[count].phone);

    count++;
    printf("\nCustomer added successfully!\n");
}

void viewCustomers() {
    printf("\n--- Customer List ---\n");
    for(int i = 0; i < count; i++) {
        printf("\nID: %d\nName: %s\nEmail: %s\nPhone: %s\n",
               c[i].id, c[i].name, c[i].email, c[i].phone);
    }
}

void searchCustomer() {
    int id, found = 0;
    printf("\nEnter Customer ID to search: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(c[i].id == id) {
            printf("\nCustomer Found:\n");
            printf("Name: %s\nEmail: %s\nPhone: %s\n",
                   c[i].name, c[i].email, c[i].phone);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nCustomer not found!\n");
}

void updateCustomer() {
    int id;
    printf("\nEnter Customer ID to update: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(c[i].id == id) {
            printf("Enter New Name: ");
            scanf("%s", c[i].name);

            printf("Enter New Email: ");
            scanf("%s", c[i].email);

            printf("Enter New Phone: ");
            scanf("%s", c[i].phone);

            printf("\nCustomer updated successfully!\n");
            return;
        }
    }
    printf("\nCustomer not found!\n");
}

void deleteCustomer() {
    int id;
    printf("\nEnter Customer ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(c[i].id == id) {
            for(int j = i; j < count - 1; j++) {
                c[j] = c[j + 1];
            }
            count--;
            printf("\nCustomer deleted successfully!\n");
            return;
        }
    }
    printf("\nCustomer not found!\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n--- Online CRM System ---\n");
        printf("1. Add Customer\n");
        printf("2. View Customers\n");
        printf("3. Search Customer\n");
        printf("4. Update Customer\n");
        printf("5. Delete Customer\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addCustomer(); break;
            case 2: viewCustomers(); break;
            case 3: searchCustomer(); break;
            case 4: updateCustomer(); break;
            case 5: deleteCustomer(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
