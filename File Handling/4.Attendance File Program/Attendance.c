#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[30];
    char status[10];   // Present / Absent
};

void addStudent() {
    FILE *fp = fopen("attendance.txt", "a");
    struct Student s;

    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Attendance (Present/Absent): ");
    scanf("%s", s.status);

    fprintf(fp, "%d %s %s\n", s.roll, s.name, s.status);
    fclose(fp);

    printf("Attendance Recorded Successfully!\n");
}

void viewAttendance() {
    FILE *fp = fopen("attendance.txt", "r");
    struct Student s;

    if (fp == NULL) {
        printf("No attendance records found!\n");
        return;
    }

    printf("\nRoll\tName\t\tStatus\n");
    printf("---------------------------------\n");

    while (fscanf(fp, "%d %s %s", &s.roll, s.name, s.status) != EOF) {
        printf("%d\t%-10s\t%s\n", s.roll, s.name, s.status);
    }

    fclose(fp);
}

void searchAttendance() {
    FILE *fp = fopen("attendance.txt", "r");
    struct Student s;
    int roll, found = 0;

    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    while (fscanf(fp, "%d %s %s", &s.roll, s.name, s.status) != EOF) {
        if (s.roll == roll) {
            printf("Roll: %d\nName: %s\nStatus: %s\n",
                   s.roll, s.name, s.status);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found!\n");

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n--- Attendance Management System ---\n");
        printf("1. Add Attendance\n");
        printf("2. View Attendance\n");
        printf("3. Search Attendance\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewAttendance(); break;
            case 3: searchAttendance(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
