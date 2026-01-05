#include <stdio.h>

int main() {
    int pin = 1234, enteredPin, choice;
    float balance = 10000, amount;

    printf("Enter ATM PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin) {
        printf("Invalid PIN\n");
        return 0;
    }

    do {
        printf("\n--- ATM Menu ---");
        printf("\n1. Balance\n2. Withdraw\n3. Deposit\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Balance: %.2f\n", balance);
            break;

        case 2:
            printf("Enter withdraw amount: ");
            scanf("%f", &amount);
            if (amount <= balance) {
                balance -= amount;
                printf("Collect your cash\n");
            } else {
                printf("Insufficient Balance\n");
            }
            break;

        case 3:
            printf("Enter deposit amount: ");
            scanf("%f", &amount);
            balance += amount;
            printf("Amount Deposited\n");
            break;
        }
    } while (choice != 4);

    return 0;
}
