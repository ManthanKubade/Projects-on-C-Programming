#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Insurance {
    int policyID;
    char holderName[50];
    char policyType[20];
    int duration;
    float premium;
};

void addPolicy() {
    FILE *fp = fopen("insurance.dat", "ab");
    struct Insurance i;

    printf("Enter Policy ID: ");
    scanf("%d", &i.policyID);

    printf("Enter Policy Holder Name: ");
    scanf(" %[^\n]", i.holderName);

    printf("Enter Policy Type (Life/Health/Vehicle): ");
    scanf("%s", i.policyType);

    printf("Enter Duration (Years): ");
    scanf("%d", &i.duration);

    i.premium = i.duration * 2500;

    fwrite(&i, sizeof(i), 1, fp);
    fclose(fp);

    printf("\nPolicy Added Successfully!\n");
}

void viewPolicies() {
    FILE *fp = fopen("insurance.dat", "rb");
    struct Insurance i;

    printf("\n--- Policy Records ---\n");
    while (fread(&i, sizeof(i), 1, fp)) {
        printf("\nID: %d\nName: %s\nType: %s\nDuration: %d Years\nPremium: %.2f\n",
               i.policyID, i.holderName, i.policyType, i.duration, i.premium);
    }
    fclose(fp);
}

void searchPolicy() {
    FILE *fp = fopen("insurance.dat", "rb");
    struct Insurance i;
    int id, found = 0;

    printf("Enter Policy ID to search: ");
    scanf("%d", &id);

    while (fread(&i, sizeof(i), 1, fp)) {
        if (i.policyID == id) {
            printf("\nPolicy Found!\nName: %s\nType: %s\nPremium: %.2f\n",
                   i.holderName, i.policyType, i.premium);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("\nPolicy Not Found!\n");

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n--- Insurance Record System ---");
        printf("\n1. Add Policy");
        printf("\n2. View Policies");
        printf("\n3. Search Policy");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPolicy(); break;
            case 2: viewPolicies(); break;
            case 3: searchPolicy(); break;
            case 4: exit(0);
            default: printf("Invalid Choice!");
        }
    } while (choice != 4);

    return 0;
}

