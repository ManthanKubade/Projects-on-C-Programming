#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define OVERS 5
#define BALLS 6

int main() {
    int runs = 0, wickets = 0;
    srand(time(NULL));

    printf("\n🏏 Cricket Match Simulation Started\n");

    for(int over = 1; over <= OVERS && wickets < 10; over++) {
        printf("\nOver %d:\n", over);

        for(int ball = 1; ball <= BALLS; ball++) {
            int outcome = rand() % 8; // 0-6 runs, 7 = wicket

            if(outcome == 7) {
                wickets++;
                printf("Ball %d: WICKET! Total: %d/%d\n", ball, runs, wickets);
                if(wickets == 10) break;
            } else {
                runs += outcome;
                printf("Ball %d: %d runs | Total: %d/%d\n", ball, outcome, runs, wickets);
            }

            sleep(1);
        }
    }

    printf("\n🏁 Innings Over! Final Score: %d/%d\n", runs, wickets);
    return 0;
}
