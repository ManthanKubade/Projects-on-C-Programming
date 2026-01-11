#include <stdio.h>
#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int token) {
    if(rear == SIZE - 1)
        printf("Queue Full!\n");
    else {
        if(front == -1) front = 0;
        queue[++rear] = token;
        printf("Token %d added\n", token);
    }
}

void dequeue() {
    if(front == -1 || front > rear)
        printf("No customers in queue\n");
    else
        printf("Serving Token %d\n", queue[front++]);
}

void display() {
    if(front == -1 || front > rear)
        printf("Queue Empty\n");
    else {
        printf("Waiting Queue: ");
        for(int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, token = 1;

    while(1) {
        printf("\n1.Generate Token\n2.Serve Customer\n3.Display Queue\n4.Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: enqueue(token++); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
        }
    }
}
