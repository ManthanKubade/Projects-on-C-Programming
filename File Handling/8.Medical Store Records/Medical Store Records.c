#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    int id;
    char name[50];
    char company[50];
    int qty;
    float price;
    char expiry[15];
};

void addMedicine();
void viewMedicine();
void searchMedicine();
void updateMedicine();
void deleteMedicine();
void sellMedicine();
void lowStock();
void expiryReport();

FILE *fp;

int main() {
    int choice;

    while(1) {
        printf("\n===== MEDICAL STORE MANAGEMENT =====\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Sell Medicine\n");
        printf("7. Low Stock Report\n");
        printf("8. Expiry Report\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addMedicine(); break;
            case 2: viewMedicine(); break;
            case 3: searchMedicine(); break;
            case 4: updateMedicine(); break;
            case 5: deleteMedicine(); break;
            case 6: sellMedicine(); break;
            case 7: lowStock(); break;
            case 8: expiryReport(); break;
            case 9: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
    return 0;
}

void addMedicine() {
    struct Medicine m;
    fp = fopen("medicine.dat", "ab");

    printf("Enter ID: ");
    scanf("%d", &m.id);
    printf("Enter Name: ");
    scanf("%s", m.name);
    printf("Enter Company: ");
    scanf("%s", m.company);
    printf("Enter Quantity: ");
    scanf("%d", &m.qty);
    printf("Enter Price: ");
    scanf("%f", &m.price);
    printf("Enter Expiry (MM/YYYY): ");
    scanf("%s", m.expiry);

    fwrite(&m, sizeof(m), 1, fp);
    fclose(fp);

    printf("\nMedicine Added Successfully!\n");
}

void viewMedicine() {
    struct Medicine m;
    fp = fopen("medicine.dat", "rb");

    printf("\nID\tName\tCompany\tQty\tPrice\tExpiry\n");
    while(fread(&m, sizeof(m), 1, fp)) {
        printf("%d\t%s\t%s\t%d\t%.2f\t%s\n", m.id, m.name, m.company, m.qty, m.price, m.expiry);
    }
    fclose(fp);
}

void searchMedicine() {
    struct Medicine m;
    int id, found = 0;
    fp = fopen("medicine.dat", "rb");

    printf("Enter Medicine ID to search: ");
    scanf("%d", &id);

    while(fread(&m, sizeof(m), 1, fp)) {
        if(m.id == id) {
            printf("\nFound: %s | Stock: %d | Price: %.2f\n", m.name, m.qty, m.price);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if(!found) printf("Medicine Not Found!\n");
}

void updateMedicine() {
    struct Medicine m;
    int id, found = 0;

    fp = fopen("medicine.dat", "rb+");

    printf("Enter Medicine ID to update: ");
    scanf("%d", &id);

    while(fread(&m, sizeof(m), 1, fp)) {
        if(m.id == id) {
            printf("Enter New Quantity: ");
            scanf("%d", &m.qty);
            printf("Enter New Price: ");
            scanf("%f", &m.price);

            fseek(fp, -sizeof(m), SEEK_CUR);
            fwrite(&m, sizeof(m), 1, fp);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if(found) printf("Record Updated Successfully!\n");
    else printf("Medicine Not Found!\n");
}

void deleteMedicine() {
    struct Medicine m;
    int id, found = 0;

    FILE *temp = fopen("temp.dat", "wb");
    fp = fopen("medicine.dat", "rb");

    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);

    while(fread(&m, sizeof(m), 1, fp)) {
        if(m.id != id) {
            fwrite(&m, sizeof(m), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("medicine.dat");
    rename("temp.dat", "medicine.dat");

    if(found) printf("Medicine Deleted Successfully!\n");
    else printf("Medicine Not Found!\n");
}

void sellMedicine() {
    struct Medicine m;
    int id, qty, found = 0;
    float total;

    fp = fopen("medicine.dat", "rb+");

    printf("Enter Medicine ID: ");
    scanf("%d", &id);
    printf("Enter Quantity: ");
    scanf("%d", &qty);

    while(fread(&m, sizeof(m), 1, fp)) {
        if(m.id == id) {
            if(m.qty >= qty) {
                m.qty -= qty;
                total = qty * m.price;

                fseek(fp, -sizeof(m), SEEK_CUR);
                fwrite(&m, sizeof(m), 1, fp);

                printf("\nBill Generated\n");
                printf("---------------------\n");
                printf("Medicine: %s\n", m.name);
                printf("Qty: %d\n", qty);
                printf("Total: %.2f\n", total);
                printf("---------------------\n");
            } else {
                printf("Insufficient Stock!\n");
            }
            found = 1;
            break;
        }
    }
    fclose(fp);

    if(!found) printf("Medicine Not Found!\n");
}

void lowStock() {
    struct Medicine m;
    fp = fopen("medicine.dat", "rb");

    printf("\nLow Stock Medicines (Qty < 10)\n");
    while(fread(&m, sizeof(m), 1, fp)) {
        if(m.qty < 10) {
            printf("%s | Stock: %d\n", m.name, m.qty);
        }
    }
    fclose(fp);
}

void expiryReport() {
    struct Medicine m;
    fp = fopen("medicine.dat", "rb");

    printf("\nExpiry Report\n");
    while(fread(&m, sizeof(m), 1, fp)) {
        printf("%s | Expiry: %s\n", m.name, m.expiry);
    }
    fclose(fp);
}
