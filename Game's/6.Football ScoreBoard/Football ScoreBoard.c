#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int teamA = 0, teamB = 0;
    srand(time(NULL));

    printf("\n⚽ Football Match Live Scoreboard\n");
    printf("Team A vs Team B\n\n");

    for(int minute = 1; minute <= 90; minute += 5) {
        int chance = rand() % 10;

        if(chance == 1) {
            teamA++;
            printf("⚽ Goal for Team A at %d minute!\n", minute);
        }
        if(chance == 2) {
            teamB++;
            printf("⚽ Goal for Team B at %d minute!\n", minute);
        }

        printf("Time: %d min | Score: Team A %d - %d Team B\n",
               minute, teamA, teamB);

        sleep(1);
    }

    printf("\n🏁 Match Over!\nFinal Score: Team A %d - %d Team B\n", teamA, teamB);

    return 0;
}
