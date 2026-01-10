#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    int regId;
    char name[50];
    char examName[50];
    char subject[50];
    char center[50];
};

void registerCandidate();
void viewCandidates();
void searchCandidate();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;

    while (1) {
        printf("\n===== EXAM REGISTRATION SYSTEM =====\n");
        printf("1. Register New Candidate\n");
        printf("2. View All Candidates\n");
        printf("3. Search Candidate by Registration ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            registerCandidate();
            break;
        case 2:
            viewCandidates();
            break;
        case 3:
            searchCandidate();
            break;
        case 4:
            printf("Thank you for using Exam Registration System!\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

void registerCandidate() {
    struct Candidate c;
    FILE *fp = fopen("exam_records.dat", "ab");

    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("\nEnter Registration ID: ");
    scanf("%d", &c.regId);

    printf("Enter Candidate Name: ");
    scanf(" %[^\n]", c.name);

    printf("Enter Exam Name: ");
    scanf(" %[^\n]", c.examName);

    printf("Enter Subject: ");
    scanf(" %[^\n]", c.subject);

    printf("Enter Exam Center: ");
    scanf(" %[^\n]", c.center);

    fwrite(&c, sizeof(c), 1, fp);
    fclose(fp);

    printf("\nCandidate Registered Successfully!\n");
}

void viewCandidates() {
    struct Candidate c;
    FILE *fp = fopen("exam_records.dat", "rb");

    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n===== REGISTERED CANDIDATES =====\n");

    while (fread(&c, sizeof(c), 1, fp)) {
        printf("\nRegistration ID: %d", c.regId);
        printf("\nName: %s", c.name);
        printf("\nExam: %s", c.examName);
        printf("\nSubject: %s", c.subject);
        printf("\nCenter: %s", c.center);
        printf("\n-------------------------------");
    }

    fclose(fp);
}

void searchCandidate() {
    struct Candidate c;
    int id, found = 0;
    FILE *fp = fopen("exam_records.dat", "rb");

    if (fp == NULL) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nEnter Registration ID to search: ");
    scanf("%d", &id);

    while (fread(&c, sizeof(c), 1, fp)) {
        if (c.regId == id) {
            printf("\n===== CANDIDATE FOUND =====");
            printf("\nRegistration ID: %d", c.regId);
            printf("\nName: %s", c.name);
            printf("\nExam: %s", c.examName);
            printf("\nSubject: %s", c.subject);
            printf("\nCenter: %s", c.center);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nCandidate not found!\n");
    }

    fclose(fp);
}
