#include <stdio.h>

struct Member {
    char name[20];
    float paid;
};

int main() {
    int n;
    float total = 0, share;

    printf("Enter number of group members: ");
    scanf("%d", &n);

    struct Member m[n];

    for(int i = 0; i < n; i++) {
        printf("Enter name of member %d: ", i+1);
        scanf("%s", m[i].name);

        printf("Enter amount paid by %s: ₹", m[i].name);
        scanf("%f", &m[i].paid);

        total += m[i].paid;
    }

    share = total / n;

    printf("\nTotal Expense: ₹%.2f", total);
    printf("\nEach person should pay: ₹%.2f\n", share);

    printf("\n--- Settlement ---\n");

    for(int i = 0; i < n; i++) {
        float diff = m[i].paid - share;

        if(diff > 0)
            printf("%s should receive ₹%.2f\n", m[i].name, diff);
        else if(diff < 0)
            printf("%s should pay ₹%.2f\n", m[i].name, -diff);
        else
            printf("%s is settled.\n", m[i].name);
    }

    return 0;
}
