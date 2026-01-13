#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student s[MAX];
int n = 0;

/* Function Prototypes */
void addStudent();
void displayStudents();
void sortStudents();
void buildHeap();
void heapify(int i);
void showTopper();

void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int choice;

    do {
        printf("\n--- Student Ranking System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Sort by Marks\n");
        printf("4. Show Topper (Heap)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: sortStudents(); break;
            case 4: showTopper(); break;
            case 5: exit(0);
            default: printf("Invalid Choice!\n");
        }
    } while(choice != 5);

    return 0;
}

void addStudent() {
    printf("Enter Roll No: ");
    scanf("%d", &s[n].roll);
    printf("Enter Name: ");
    scanf("%s", s[n].name);
    printf("Enter Marks: ");
    scanf("%f", &s[n].marks);
    n++;
    printf("Student Added Successfully!\n");
}

void displayStudents() {
    printf("\nRoll\tName\tMarks\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
}

void sortStudents() {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(s[j].marks < s[j+1].marks) {
                swap(&s[j], &s[j+1]);
            }
        }
    }
    printf("Students Sorted by Marks (Ranking Generated)\n");
}

void heapify(int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && s[left].marks > s[largest].marks)
        largest = left;

    if(right < n && s[right].marks > s[largest].marks)
        largest = right;

    if(largest != i) {
        swap(&s[i], &s[largest]);
        heapify(largest);
    }
}

void buildHeap() {
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(i);
    }
}

void showTopper() {
    buildHeap();
    printf("\nTopper Details:\n");
    printf("Roll: %d\n", s[0].roll);
    printf("Name: %s\n", s[0].name);
    printf("Marks: %.2f\n", s[0].marks);
}
