#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getColor(int number) {
    if (number == 0) return 0;   // Green
    if (number % 2 == 0) return 1; // Black
    return 2; // Red
}

int main() {
    int balance = 1000;
    int betType, betNumber, betAmount;
    srand(time(NULL));

    printf("\n🎰 Welcome to Casino Roulette Simulation\n");

    while (balance > 0) {
        printf("\nCurrent Balance: ₹%d\n", balance);
        printf("Choose Bet Type:\n");
        printf("1. Number Bet (Payout 35x)\n");
        printf("2. Color Bet (Payout 2x)\n");
        printf("3. Odd/Even Bet (Payout 2x)\n");
        printf("0. Exit\n");
        scanf("%d", &betType);

        if (betType == 0) break;

        printf("Enter Bet Amount: ");
        scanf("%d", &betAmount);

        if (betAmount > balance) {
            printf("❌ Insufficient balance!\n");
            continue;
        }

        int win = 0;
        int result = rand() % 37;  // 0–36

        if (betType == 1) {
            printf("Choose Number (0-36): ");
            scanf("%d", &betNumber);
            if (betNumber == result) {
                balance += betAmount * 35;
                win = 1;
            } else {
                balance -= betAmount;
            }
        }

        if (betType == 2) {
            int colorChoice;
            printf("Choose Color (1=Black, 2=Red): ");
            scanf("%d", &colorChoice);

            if (getColor(result) == colorChoice) {
                balance += betAmount;
                win = 1;
            } else {
                balance -= betAmount;
            }
        }

        if (betType == 3) {
            int oddEven;
            printf("Choose (1=Odd, 2=Even): ");
            scanf("%d", &oddEven);

            if (result != 0 &&
               ((result % 2 == 0 && oddEven == 2) ||
                (result % 2 == 1 && oddEven == 1))) {
                balance += betAmount;
                win = 1;
            } else {
                balance -= betAmount;
            }
        }

        printf("\n🎡 Wheel Result: %d\n", result);

        if (win)
            printf("🎉 You Win!\n");
        else
            printf("💸 You Lose!\n");

        if (balance <= 0) {
            printf("\n❌ You are out of money!\n");
            break;
        }
    }

    printf("\nThanks for playing! Final Balance: ₹%d\n", balance);
    return 0;
}
