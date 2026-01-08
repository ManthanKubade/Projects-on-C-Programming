#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

void addItem() {
    FILE *fp = fopen("warehouse.dat", "ab");
    struct Item it;
    printf("Enter Item ID: ");
    scanf("%d", &it.id);
    printf("Enter Item Name: ");
    scanf("%s", it.name);
    printf("Enter Quantity: ");
    scanf("%d", &it.quantity);
    printf("Enter Price: ");
    scanf("%f", &it.price);
    fwrite(&it, sizeof(it), 1, fp);
    fclose(fp);
    printf("Item added successfully!\n");
}

void displayItems() {
    FILE *fp = fopen("warehouse.dat", "rb");
    struct Item it;
    printf("\nID\tName\tQty\tPrice\n");
    while (fread(&it, sizeof(it), 1, fp)) {
        printf("%d\t%s\t%d\t%.2f\n", it.id, it.name, it.quantity, it.price);
    }
    fclose(fp);
}

void updateStock() {
    FILE *fp = fopen("warehouse.dat", "rb+");
    struct Item it;
    int id, found = 0, qty;
    printf("Enter Item ID to update: ");
    scanf("%d", &id);

    while (fread(&it, sizeof(it), 1, fp)) {
        if (it.id == id) {
            printf("Enter quantity to add/remove (+/-): ");
            scanf("%d", &qty);
            it.quantity += qty;
            fseek(fp, -sizeof(it), SEEK_CUR);
            fwrite(&it, sizeof(it), 1, fp);
            found = 1;
            break;
        }
    }
    fclose(fp);
    if (found)
        printf("Stock updated successfully!\n");
    else
        printf("Item not found!\n");
}

void lowStockAlert() {
    FILE *fp = fopen("warehouse.dat", "rb");
    struct Item it;
    printf("\nLow Stock Items (Qty < 10):\n");
    while (fread(&it, sizeof(it), 1, fp)) {
        if (it.quantity < 10)
            printf("%s (%d units)\n", it.name, it.quantity);
    }
    fclose(fp);
}

int main() {
    int choice;
    do {
        printf("\n--- Warehouse Stock System ---\n");
        printf("1. Add Item\n2. Display Items\n3. Update Stock\n4. Low Stock Alert\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: updateStock(); break;
            case 4: lowStockAlert(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    } while (1);
    return 0;
}
