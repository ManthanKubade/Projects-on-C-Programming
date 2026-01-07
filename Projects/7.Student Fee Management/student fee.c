#include <stdio.h>

struct Student {
    int roll;
    char name[30];
    float totalFee;
    float paidFee;
};

int main() {
    struct Student s;
    FILE *fp;
    int n, i;
    float pending;

    fp = fopen("fees.txt", "w");

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nStudent %d Roll No: ", i + 1);
        scanf("%d", &s.roll);

        printf("Student Name: ");
        scanf("%s", s.name);

        printf("Total Fee: ");
        scanf("%f", &s.totalFee);

        printf("Paid Fee: ");
        scanf("%f", &s.paidFee);

        pending = s.totalFee - s.paidFee;

        fprintf(fp, "%d %s %.2f %.2f %.2f\n",
                s.roll, s.name, s.totalFee, s.paidFee, pending);
    }

    fclose(fp);

    fp = fopen("fees.txt", "r");

    printf("\n------ Student Fee Records ------\n");
    printf("Roll\tName\tTotal\tPaid\tPending\n");

    while(fscanf(fp, "%d %s %f %f %f",
          &s.roll, s.name, &s.totalFee, &s.paidFee, &pending) != EOF) {

        printf("%d\t%s\t%.2f\t%.2f\t%.2f\n",
               s.roll, s.name, s.totalFee, s.paidFee, pending);
    }

    fclose(fp);
    return 0;
}
