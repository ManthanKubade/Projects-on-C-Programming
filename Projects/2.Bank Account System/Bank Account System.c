#include <stdio.h>

int main() {
    int choice;
    float balance = 5000, amount;

    do {
        printf("\n--- Bank Account System ---");
        printf("\n1. Deposit\n2. Withdraw\n3. Balance Check\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            balance += amount;
            printf("Deposited Successfully\n");
            break;

        case 2:
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= balance) {
                balance -= amount;
                printf("Withdraw Successful\n");
            } else {
                printf("Insufficient Balance\n");
            }
            break;

        case 3:
            printf("Current Balance: %.2f\n", balance);
            break;
        }
    } while (choice != 4);

    return 0;
}
