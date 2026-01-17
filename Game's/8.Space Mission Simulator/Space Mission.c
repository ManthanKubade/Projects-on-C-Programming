#include <stdio.h>
#include <stdlib.h>

#define TOTAL_DISTANCE 5000   // km
#define FUEL_RATE 5          // fuel per 100 km

int main() {
    int fuel = 300;
    int distance = 0;

    printf("\n🚀 Space Mission Simulator Started\n");

    while (distance < TOTAL_DISTANCE && fuel > 0) {
        distance += 100;
        fuel -= FUEL_RATE;

        printf("Distance Covered: %d km | Fuel Left: %d units\n", distance, fuel);

        if (fuel <= 50)
            printf("⚠ Warning: Low Fuel!\n");
    }

    if (fuel > 0)
        printf("\n✅ Mission Successful! Destination Reached.\n");
    else
        printf("\n❌ Mission Failed! Fuel Exhausted.\n");

    return 0;
}
