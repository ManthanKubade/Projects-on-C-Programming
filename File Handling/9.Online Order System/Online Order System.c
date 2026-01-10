#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Order {
    int orderId;
    char customerName[50];
    char productName[50];
    int quantity;
    float price;
    float total;
};

void addOrder();
void viewOrders();
void searchOrder();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;

    while (1) {
        printf("\n===== ONLINE ORDER SYSTEM =====\n");
        printf("1. Add New Order\n");
        printf("2. View All Orders\n");
        printf("3. Search Order by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addOrder();
            break;
        case 2:
            viewOrders();
            break;
        case 3:
            searchOrder();
            break;
        case 4:
            printf("Thank you for using Online Order System!\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

void addOrder() {
    struct Order o;
    FILE *fp = fopen("orders.dat", "ab");

    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("\nEnter Order ID: ");
    scanf("%d", &o.orderId);

    printf("Enter Customer Name: ");
    scanf(" %[^\n]", o.customerName);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", o.productName);

    printf("Enter Quantity: ");
    scanf("%d", &o.quantity);

    printf("Enter Price per Item: ");
    scanf("%f", &o.price);

    o.total = o.quantity * o.price;

    fwrite(&o, sizeof(o), 1, fp);
    fclose(fp);

    printf("\nOrder Added Successfully!");
    printf("\nTotal Bill Amount: %.2f\n", o.total);
}

void viewOrders() {
    struct Order o;
    FILE *fp = fopen("orders.dat", "rb");

    if (fp == NULL) {
        printf("\nNo orders found!\n");
        return;
    }

    printf("\n===== ALL ORDERS =====\n");

    while (fread(&o, sizeof(o), 1, fp)) {
        printf("\nOrder ID: %d", o.orderId);
        printf("\nCustomer: %s", o.customerName);
        printf("\nProduct: %s", o.productName);
        printf("\nQuantity: %d", o.quantity);
        printf("\nPrice: %.2f", o.price);
        printf("\nTotal Bill: %.2f", o.total);
        printf("\n-----------------------------");
    }

    fclose(fp);
}

void searchOrder() {
    struct Order o;
    int id, found = 0;
    FILE *fp = fopen("orders.dat", "rb");

    if (fp == NULL) {
        printf("\nNo orders found!\n");
        return;
    }

    printf("\nEnter Order ID to search: ");
    scanf("%d", &id);

    while (fread(&o, sizeof(o), 1, fp)) {
        if (o.orderId == id) {
            printf("\n===== ORDER FOUND =====");
            printf("\nOrder ID: %d", o.orderId);
            printf("\nCustomer: %s", o.customerName);
            printf("\nProduct: %s", o.productName);
            printf("\nQuantity: %d", o.quantity);
            printf("\nPrice: %.2f", o.price);
            printf("\nTotal Bill: %.2f", o.total);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nOrder not found!\n");
    }

    fclose(fp);
}
