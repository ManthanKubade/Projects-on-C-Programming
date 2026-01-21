#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[30];
    char skill[20];
    float cgpa;
};

struct Company {
    int id;
    char name[30];
    char skill_req[20];
    float min_cgpa;
};

struct Student students[50];
struct Company companies[50];

int scount = 0, ccount = 0;

void addStudent() {
    printf("\nEnter Student ID: ");
    scanf("%d", &students[scount].id);

    printf("Enter Name: ");
    scanf("%s", students[scount].name);

    printf("Enter Skill: ");
    scanf("%s", students[scount].skill);

    printf("Enter CGPA: ");
    scanf("%f", &students[scount].cgpa);

    scount++;
    printf("Student added successfully!\n");
}

void addCompany() {
    printf("\nEnter Company ID: ");
    scanf("%d", &companies[ccount].id);

    printf("Enter Company Name: ");
    scanf("%s", companies[ccount].name);

    printf("Required Skill: ");
    scanf("%s", companies[ccount].skill_req);

    printf("Minimum CGPA: ");
    scanf("%f", &companies[ccount].min_cgpa);

    ccount++;
    printf("Company added successfully!\n");
}

void matchJobs() {
    printf("\n--- Job Matching Results ---\n");

    for(int i = 0; i < scount; i++) {
        printf("\nStudent: %s\n", students[i].name);
        int found = 0;

        for(int j = 0; j < ccount; j++) {
            if(strcmp(students[i].skill, companies[j].skill_req) == 0 &&
               students[i].cgpa >= companies[j].min_cgpa) {

                printf("  Eligible for: %s\n", companies[j].name);
                found = 1;
            }
        }

        if(!found)
            printf("  No matching jobs found\n");
    }
}

void viewData() {
    printf("\n--- Students ---\n");
    for(int i = 0; i < scount; i++) {
        printf("%d  %s  %s  %.2f\n",
            students[i].id, students[i].name,
            students[i].skill, students[i].cgpa);
    }

    printf("\n--- Companies ---\n");
    for(int i = 0; i < ccount; i++) {
        printf("%d  %s  %s  %.2f\n",
            companies[i].id, companies[i].name,
            companies[i].skill_req, companies[i].min_cgpa);
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n--- Student Placement System ---\n");
        printf("1. Add Student\n");
        printf("2. Add Company\n");
        printf("3. Match Jobs\n");
        printf("4. View Data\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: addCompany(); break;
            case 3: matchJobs(); break;
            case 4: viewData(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
