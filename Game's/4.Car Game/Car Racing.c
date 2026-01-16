#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>   // for sleep()

#define MAX_CARS 4
#define TOTAL_LAPS 5
#define MAX_SPEED 220

typedef struct {
    char name[20];
    int speed;
    int distance;
    int lap;
} Car;

void displayRace(Car cars[]) {
    printf("\n---------------- RACE STATUS ----------------\n");
    for(int i = 0; i < MAX_CARS; i++) {
        printf("%s | Speed: %3d km/h | Lap: %d | Distance: %d m\n",
               cars[i].name, cars[i].speed, cars[i].lap, cars[i].distance);
    }
    printf("--------------------------------------------\n");
}

int main() {
    Car cars[MAX_CARS] = {
        {"Ferrari", 0, 0, 1},
        {"Lamborghini", 0, 0, 1},
        {"Bugatti", 0, 0, 1},
        {"McLaren", 0, 0, 1}
    };

    srand(time(NULL));

    int raceOver = 0;

    printf("\n🏁 Car Racing Speed Simulation Started! 🏁\n");

    while (!raceOver) {
        for (int i = 0; i < MAX_CARS; i++) {
            int acceleration = rand() % 30;
            cars[i].speed += acceleration;

            if (cars[i].speed > MAX_SPEED)
                cars[i].speed = MAX_SPEED;

            cars[i].distance += cars[i].speed;

            if (cars[i].distance >= 1000) {
                cars[i].lap++;
                cars[i].distance = 0;
                printf("\n%s completed Lap %d!\n", cars[i].name, cars[i].lap - 1);
            }

            if (cars[i].lap > TOTAL_LAPS) {
                printf("\n🏆 WINNER: %s wins the race! 🏆\n", cars[i].name);
                raceOver = 1;
                break;
            }
        }

        displayRace(cars);
        sleep(1);
    }

    return 0;
}
