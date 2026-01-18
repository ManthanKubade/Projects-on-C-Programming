#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 10

int main() {
    int players[MAX_PLAYERS];
    int count = 0;

    printf("\n🎮 Online Multiplayer Lobby Simulator\n");

    while (count < MAX_PLAYERS) {
        printf("\nPlayer %d joined the lobby", count + 1);
        players[count] = count + 1000;  // player ID
        count++;

        if (count % 2 == 0) {
            printf("\n⚔ Match Created between Player %d and Player %d\n",
                   players[count-2], players[count-1]);
        }
    }

    printf("\nAll players matched successfully!\n");

    return 0;
}
