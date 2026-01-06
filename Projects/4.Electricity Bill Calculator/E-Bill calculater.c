#include <stdio.h>

float calculateEnergyCharge(int units) {
    float charge = 0;

    if (units <= 100)
        charge = units * 1.5;
    else if (units <= 200)
        charge = (100 * 1.5) + (units - 100) * 2.5;
    else if (units <= 500)
        charge = (100 * 1.5) + (100 * 2.5) + (units - 200) * 4.0;
    else
        charge = (100 * 1.5) + (100 * 2.5) + (300 * 4.0) + (units - 500) * 6.0;

    return charge;
}

int main() {
    int units;
    float energyCharge, fixedCharge = 75, duty, total;
    char name[50];

    printf("Enter Customer Name: ");
    scanf("%s", name);

    printf("Enter Units Consumed: ");
    scanf("%d", &units);

    energyCharge = calculateEnergyCharge(units);
    duty = energyCharge * 0.05;
    total = energyCharge + fixedCharge + duty;

    printf("\n----- Electricity Bill -----\n");
    printf("Customer Name      : %s\n", name);
    printf("Units Consumed     : %d\n", units);
    printf("Energy Charge (₹)  : %.2f\n", energyCharge);
    printf("Fixed Charge (₹)   : %.2f\n", fixedCharge);
    printf("Electricity Duty   : %.2f\n", duty);
    printf("------------------------------\n");
    printf("Total Bill Amount  : ₹%.2f\n", total);

    return 0;
}
