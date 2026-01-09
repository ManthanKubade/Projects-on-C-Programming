#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ticket {
    int ticketNo;
    char name[50];
    int age;
    char train[30];
    char source[30];
    char destination[30];
    char date[15];
    int seat;
};

void bookTicket();
void viewTickets();
void searchTicket();
void deleteTicket();

int main() {
    int choice;
    
    do {
        printf("\n===== Railway Ticket Records System =====\n");
        printf("1. Book Ticket\n");
        printf("2. View All Tickets\n");
        printf("3. Search Ticket\n");
        printf("4. Cancel Ticket\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: bookTicket(); break;
            case 2: viewTickets(); break;
            case 3: searchTicket(); break;
            case 4: deleteTicket(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}

void bookTicket() {
    struct Ticket t;
    FILE *fp = fopen("tickets.dat", "ab");

    printf("Enter Ticket Number: ");
    scanf("%d", &t.ticketNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", t.name);

    printf("Enter Age: ");
    scanf("%d", &t.age);

    printf("Enter Train Name: ");
    scanf(" %[^\n]", t.train);

    printf("Enter Source: ");
    scanf(" %[^\n]", t.source);

    printf("Enter Destination: ");
    scanf(" %[^\n]", t.destination);

    printf("Enter Journey Date (DD/MM/YYYY): ");
    scanf("%s", t.date);

    printf("Enter Seat Number: ");
    scanf("%d", &t.seat);

    fwrite(&t, sizeof(t), 1, fp);
    fclose(fp);

    printf("\nTicket Booked Successfully!\n");
}

void viewTickets() {
    struct Ticket t;
    FILE *fp = fopen("tickets.dat", "rb");

    if(fp == NULL) {
        printf("No tickets found!\n");
        return;
    }

    while(fread(&t, sizeof(t), 1, fp)) {
        printf("\nTicket No: %d\nName: %s\nAge: %d\nTrain: %s\nFrom: %s\nTo: %s\nDate: %s\nSeat: %d\n",
               t.ticketNo, t.name, t.age, t.train, t.source, t.destination, t.date, t.seat);
    }

    fclose(fp);
}

void searchTicket() {
    struct Ticket t;
    int id, found = 0;
    FILE *fp = fopen("tickets.dat", "rb");

    printf("Enter Ticket Number to search: ");
    scanf("%d", &id);

    while(fread(&t, sizeof(t), 1, fp)) {
        if(t.ticketNo == id) {
            printf("\nTicket Found:\n");
            printf("Name: %s\nTrain: %s\nFrom: %s\nTo: %s\nDate: %s\nSeat: %d\n",
                   t.name, t.train, t.source, t.destination, t.date, t.seat);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Ticket not found!\n");

    fclose(fp);
}

void deleteTicket() {
    struct Ticket t;
    int id;
    FILE *fp = fopen("tickets.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    printf("Enter Ticket Number to cancel: ");
    scanf("%d", &id);

    while(fread(&t, sizeof(t), 1, fp)) {
        if(t.ticketNo != id) {
            fwrite(&t, sizeof(t), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("tickets.dat");
    rename("temp.dat", "tickets.dat");

    printf("Ticket Cancelled Successfully!\n");
}
