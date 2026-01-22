#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[30];
    int present;
};

struct Student students[50];
char chat[100][100];

int scount = 0, msgCount = 0;

void addStudent() {
    printf("Enter Roll No: ");
    scanf("%d", &students[scount].roll);

    printf("Enter Name: ");
    scanf("%s", students[scount].name);

    students[scount].present = 0;
    scount++;
}

void markAttendance() {
    int roll;
    printf("Enter Roll No to mark present: ");
    scanf("%d", &roll);

    for(int i = 0; i < scount; i++) {
        if(students[i].roll == roll) {
            students[i].present = 1;
            printf("Attendance marked for %s\n", students[i].name);
            return;
        }
    }
    printf("Student not found!\n");
}

void viewAttendance() {
    printf("\n--- Attendance List ---\n");
    for(int i = 0; i < scount; i++) {
        printf("%d  %s  %s\n",
            students[i].roll,
            students[i].name,
            students[i].present ? "Present" : "Absent");
    }
}

void sendMessage() {
    getchar(); // clear buffer
    printf("Enter message: ");
    fgets(chat[msgCount], 100, stdin);
    msgCount++;
}

void viewChat() {
    printf("\n--- Classroom Chat ---\n");
    for(int i = 0; i < msgCount; i++) {
        printf("%s", chat[i]);
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n--- Virtual Classroom ---\n");
        printf("1. Add Student\n");
        printf("2. Mark Attendance\n");
        printf("3. View Attendance\n");
        printf("4. Send Message\n");
        printf("5. View Chat\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: markAttendance(); break;
            case 3: viewAttendance(); break;
            case 4: sendMessage(); break;
            case 5: viewChat(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
