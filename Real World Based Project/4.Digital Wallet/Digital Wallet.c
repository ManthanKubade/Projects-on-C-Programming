#include <stdio.h>

struct Wallet {
    char name[50];
    int accountNo;
    float balance;
};

void showMenu() {
    printf("\n--- Digital Wallet Menu ---\n");
    printf("1. Check Balance\n");
    printf("2. Add Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

int main() {
    struct Wallet user;
    int choice;
    float amount;

    printf("Enter your name: ");
    scanf("%s", user.name);

    printf("Enter account number: ");
    scanf("%d", &user.accountNo);

    user.balance = 0.0;

    printf("\nAccount created successfully!\n");

    while(1) {
        showMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nCurrent Balance: ₹%.2f\n", user.balance);
                break;

            case 2:
                printf("Enter amount to add: ");
                scanf("%f", &amount);
                if(amount > 0) {
                    user.balance += amount;
                    printf("₹%.2f added successfully!\n", amount);
                } else {
                    printf("Invalid amount!\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if(amount > 0 && amount <= user.balance) {
                    user.balance -= amount;
                    printf("₹%.2f withdrawn successfully!\n", amount);
                } else {
                    printf("Insufficient balance!\n");
                }
                break;

            case 4:
                printf("Thank you for using Digital Wallet!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
