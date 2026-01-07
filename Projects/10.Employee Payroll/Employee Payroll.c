#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float basic;
    float hra, da;
    float pf, tax;
    float gross, net;
};

void calculateSalary(struct Employee *e) {
    e->hra = 0.20 * e->basic;
    e->da  = 0.10 * e->basic;
    e->gross = e->basic + e->hra + e->da;

    e->pf = 0.12 * e->basic;
    e->tax = 0.05 * e->gross;

    e->net = e->gross - (e->pf + e->tax);
}

void saveToFile(struct Employee e) {
    FILE *fp = fopen("payroll.txt", "a");
    if (fp == NULL) {
        printf("File error!\n");
        return;
    }
    fprintf(fp, "%d %s %.2f %.2f\n",
            e.id, e.name, e.basic, e.net);
    fclose(fp);
}

void displaySlip(struct Employee e) {
    printf("\n--- Salary Slip ---\n");
    printf("ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Basic Salary: %.2f\n", e.basic);
    printf("HRA: %.2f\n", e.hra);
    printf("DA: %.2f\n", e.da);
    printf("PF: %.2f\n", e.pf);
    printf("Tax: %.2f\n", e.tax);
    printf("Gross Salary: %.2f\n", e.gross);
    printf("Net Salary: %.2f\n", e.net);
}

int main() {
    struct Employee e;
    int choice;

    do {
        printf("\n1. Add Employee Payroll");
        printf("\n2. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Employee ID: ");
            scanf("%d", &e.id);

            printf("Enter Name: ");
            scanf("%s", e.name);

            printf("Enter Basic Salary: ");
            scanf("%f", &e.basic);

            calculateSalary(&e);
            displaySlip(e);
            saveToFile(e);

            printf("\nPayroll saved successfully!\n");
        }

    } while (choice != 2);

    return 0;
}
