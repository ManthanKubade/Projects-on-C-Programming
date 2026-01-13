#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>   // For Sleep()

#define MAX 100

struct Vehicle {
    int id;
    char type[20];
};

struct Vehicle queue[MAX];
int front = -1, rear = -1;

/* Function Prototypes */
void addVehicle();
void passVehicle();
void displayQueue();

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void addVehicle() {
    if(isFull()) {
        printf("Queue is Full! Traffic Jam!\n");
        return;
    }

    struct Vehicle v;
    printf("Enter Vehicle ID: ");
    scanf("%d", &v.id);
    printf("Enter Vehicle Type (Car/Bike/Bus): ");
    scanf("%s", v.type);

    if(front == -1) front = 0;
    queue[++rear] = v;

    printf("Vehicle Added to Queue\n");
}

void passVehicle() {
    if(isEmpty()) {
        printf("No vehicles waiting. Signal Green but road empty.\n");
        return;
    }

    printf("\nSignal GREEN...\n");
    Sleep(1000);

    printf("Vehicle Passed: ID %d (%s)\n", queue[front].id, queue[front].type);
    front++;

    if(front > rear) front = rear = -1;
}

void displayQueue() {
    if(isEmpty()) {
        printf("No vehicles in queue.\n");
        return;
    }

    printf("\nVehicles Waiting at Signal:\n");
    for(int i = front; i <= rear; i++) {
        printf("ID: %d  Type: %s\n", queue[i].id, queue[i].type);
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Traffic Signal Simulation ---\n");
        printf("1. Add Vehicle\n");
        printf("2. Signal Green (Pass Vehicle)\n");
        printf("3. Display Waiting Vehicles\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addVehicle(); break;
            case 2: passVehicle(); break;
            case 3: displayQueue(); break;
            case 4: exit(0);
            default: printf("Invalid Choice!\n");
        }
    } while(choice != 4);

    return 0;
}
