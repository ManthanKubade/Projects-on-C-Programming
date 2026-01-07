#include <stdio.h>

#define TOTAL_SEATS 10

int main() {
    int seats[TOTAL_SEATS] = {0}; // 0 = available, 1 = booked
    int choice, seatNo, i;

    do {
        printf("\n--- Railway Reservation System ---\n");
        printf("1. Book Seat\n");
        printf("2. Cancel Seat\n");
        printf("3. View Seat Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter seat number (1-%d): ", TOTAL_SEATS);
            scanf("%d", &seatNo);

            if(seatNo < 1 || seatNo > TOTAL_SEATS) {
                printf("Invalid seat number!\n");
            } else if(seats[seatNo - 1] == 1) {
                printf("Seat already booked!\n");
            } else {
                seats[seatNo - 1] = 1;
                printf("Seat %d booked successfully.\n", seatNo);
            }
            break;

        case 2:
            printf("Enter seat number to cancel: ");
            scanf("%d", &seatNo);

            if(seatNo < 1 || seatNo > TOTAL_SEATS) {
                printf("Invalid seat number!\n");
            } else if(seats[seatNo - 1] == 0) {
                printf("Seat already available!\n");
            } else {
                seats[seatNo - 1] = 0;
                printf("Seat %d cancelled successfully.\n", seatNo);
            }
            break;

        case 3:
            printf("\nSeat Status:\n");
            for(i = 0; i < TOTAL_SEATS; i++) {
                if(seats[i] == 0)
                    printf("Seat %d: Available\n", i + 1);
                else
                    printf("Seat %d: Booked\n", i + 1);
            }
            break;

        case 4:
            printf("Thank you for using Railway Reservation System.\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}
