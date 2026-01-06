#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants for fare calculation
#define BASE_FARE 2.50
#define PER_KM_RATE 1.50
#define PER_MINUTE_WAITING 0.25
#define PEAK_SURCHARGE_PERCENT 0.20
#define NIGHT_SURCHARGE_PERCENT 0.15
#define TOLL_FEE 5.00

// Function to check if the given hour is peak hour (7-9 AM or 5-7 PM)
bool is_peak_hour(int hour) {
    return (hour >= 7 && hour <= 9) || (hour >= 17 && hour <= 19);
}

// Function to check if the given hour is night time (10 PM to 6 AM)
bool is_night_time(int hour) {
    return hour >= 22 || hour <= 6;
}

// Function to calculate the total fare
double calculate_fare(double distance, int waiting_time, int hour, bool has_tolls) {
    double fare = BASE_FARE;
    fare += distance * PER_KM_RATE;
    fare += waiting_time * PER_MINUTE_WAITING;

    if (is_peak_hour(hour)) {
        fare += fare * PEAK_SURCHARGE_PERCENT;
    }
    if (is_night_time(hour)) {
        fare += fare * NIGHT_SURCHARGE_PERCENT;
    }
    if (has_tolls) {
        fare += TOLL_FEE;
    }

    return fare;
}

int main() {
    double distance;
    int waiting_time, hour;
    char tolls_input;
    bool has_tolls;

    printf("Taxi Fare Calculator\n");
    printf("===================\n");

    // Input distance
    printf("Enter distance traveled (in km): ");
    if (scanf("%lf", &distance) != 1 || distance < 0) {
        printf("Invalid distance. Please enter a non-negative number.\n");
        return 1;
    }

    // Input waiting time
    printf("Enter waiting time (in minutes): ");
    if (scanf("%d", &waiting_time) != 1 || waiting_time < 0) {
        printf("Invalid waiting time. Please enter a non-negative integer.\n");
        return 1;
    }

    // Input hour of the day
    printf("Enter hour of the day (0-23): ");
    if (scanf("%d", &hour) != 1 || hour < 0 || hour > 23) {
        printf("Invalid hour. Please enter an integer between 0 and 23.\n");
        return 1;
    }

    // Input tolls
    printf("Are there tolls? (y/n): ");
    scanf(" %c", &tolls_input);
    if (tolls_input == 'y' || tolls_input == 'Y') {
        has_tolls = true;
    } else if (tolls_input == 'n' || tolls_input == 'N') {
        has_tolls = false;
    } else {
        printf("Invalid input for tolls. Please enter 'y' or 'n'.\n");
        return 1;
    }

    // Calculate fare
    double total_fare = calculate_fare(distance, waiting_time, hour, has_tolls);

    // Display breakdown
    printf("\nFare Breakdown:\n");
    printf("Base Fare: $%.2f\n", BASE_FARE);
    printf("Distance Fare (%.2f km @ $%.2f/km): $%.2f\n", distance, PER_KM_RATE, distance * PER_KM_RATE);
    printf("Waiting Fare (%d min @ $%.2f/min): $%.2f\n", waiting_time, PER_MINUTE_WAITING, waiting_time * PER_MINUTE_WAITING);

    double surcharge = 0.0;
    if (is_peak_hour(hour)) {
        surcharge += total_fare * PEAK_SURCHARGE_PERCENT / (1 + PEAK_SURCHARGE_PERCENT + (is_night_time(hour) ? NIGHT_SURCHARGE_PERCENT : 0));
        printf("Peak Hour Surcharge (20%%): $%.2f\n", surcharge);
    }
    if (is_night_time(hour)) {
        surcharge += total_fare * NIGHT_SURCHARGE_PERCENT / (1 + NIGHT_SURCHARGE_PERCENT + (is_peak_hour(hour) ? PEAK_SURCHARGE_PERCENT : 0));
        printf("Night Surcharge (15%%): $%.2f\n", surcharge);
    }
    if (has_tolls) {
        printf("Tolls: $%.2f\n", TOLL_FEE);
    }

    printf("Total Fare: $%.2f\n", total_fare);

    return 0;
}
