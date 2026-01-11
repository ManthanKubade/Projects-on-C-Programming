#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    struct Student *next;
};

struct Student *head = NULL;

void addStudent() {
    struct Student *newNode = malloc(sizeof(struct Student));

    printf("Enter Roll: ");
    scanf("%d", &newNode->roll);
    printf("Enter Name: ");
    scanf("%s", newNode->name);

    newNode->next = head;
    head = newNode;

    printf("Student Added!\n");
}

void displayStudents() {
    struct Student *temp = head;
    if(!temp) {
        printf("No Records\n");
        return;
    }

    while(temp) {
        printf("Roll: %d  Name: %s\n", temp->roll, temp->name);
        temp = temp->next;
    }
}

void deleteStudent() {
    int roll;
    printf("Enter Roll to Delete: ");
    scanf("%d", &roll);

    struct Student *temp = head, *prev = NULL;

    while(temp && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if(!temp) {
        printf("Student Not Found\n");
        return;
    }

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Student Deleted!\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n1.Add Student\n2.Display Students\n3.Delete Student\n4.Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: deleteStudent(); break;
            case 4: return 0;
        }
    }
}
