#include <stdio.h>

#define GST_RATE 0.05

int main() {
    int n, i;
    float price[50], qty[50], itemTotal, subTotal = 0;
    float gstAmount, discount, grandTotal;
    char item[50][30];

    printf("Enter number of items: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nItem %d name: ", i + 1);
        scanf("%s", item[i]);

        printf("Price: ");
        scanf("%f", &price[i]);

        printf("Quantity: ");
        scanf("%f", &qty[i]);
    }

    printf("\n------------ GROCERY BILL ------------\n");
    printf("Item\tPrice\tQty\tTotal\n");

    for(i = 0; i < n; i++) {
        itemTotal = price[i] * qty[i];
        subTotal += itemTotal;
        printf("%s\t%.2f\t%.2f\t%.2f\n", item[i], price[i], qty[i], itemTotal);
    }

    gstAmount = subTotal * GST_RATE;

    printf("-------------------------------------\n");
    printf("Sub Total: %.2f\n", subTotal);
    printf("GST (5%%): %.2f\n", gstAmount);

    printf("Enter discount amount: ");
    scanf("%f", &discount);

    grandTotal = subTotal + gstAmount - discount;

    printf("-------------------------------------\n");
    printf("Grand Total: %.2f\n", grandTotal);
    printf("Thank you for shopping!\n");

    return 0;
}
