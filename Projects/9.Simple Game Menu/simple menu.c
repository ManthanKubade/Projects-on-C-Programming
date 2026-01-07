#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void guessingGame();
void rockPaperScissors();
void diceGame();

int main() {
    int choice;
    char again;

    srand(time(NULL)); // seed for random numbers

    do {
        printf("\n===== GAME MENU =====\n");
        printf("1. Number Guessing Game\n");
        printf("2. Rock Paper Scissors\n");
        printf("3. Dice Roll Game\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                guessingGame();
                break;
            case 2:
                rockPaperScissors();
                break;
            case 3:
                diceGame();
                break;
            case 4:
                printf("Thanks for playing!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

        printf("\nDo you want to return to menu? (y/n): ");
        scanf(" %c", &again);

    } while(again == 'y' || again == 'Y');

    return 0;
}

// Number Guessing Game
void guessingGame() {
    int number = rand() % 100 + 1;
    int guess, attempts = 0;

    printf("\n--- Number Guessing Game ---\n");
    printf("Guess a number between 1 and 100\n");

    do {
        scanf("%d", &guess);
        attempts++;

        if(guess > number)
            printf("Too high!\n");
        else if(guess < number)
            printf("Too low!\n");
        else
            printf("Correct! Attempts: %d\n", attempts);

    } while(guess != number);
}

// Rock Paper Scissors
void rockPaperScissors() {
    int user, computer;

    printf("\n--- Rock Paper Scissors ---\n");
    printf("1. Rock\n2. Paper\n3. Scissors\nChoose: ");
    scanf("%d", &user);

    computer = rand() % 3 + 1;

    if(user == computer)
        printf("Draw!\n");
    else if((user == 1 && computer == 3) ||
            (user == 2 && computer == 1) ||
            (user == 3 && computer == 2))
        printf("You Win!\n");
    else
        printf("Computer Wins!\n");
}

// Dice Roll Game
void diceGame() {
    int dice = rand() % 6 + 1;
    printf("\n--- Dice Roll Game ---\n");
    printf("You rolled: %d\n", dice);
}
