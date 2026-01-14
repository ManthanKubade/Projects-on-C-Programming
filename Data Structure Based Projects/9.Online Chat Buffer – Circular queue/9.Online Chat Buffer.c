#include <stdio.h>
#include <string.h>

#define MAX 5
#define MSG_SIZE 100

char chatBuffer[MAX][MSG_SIZE];
int front = -1, rear = -1;

// Check if buffer is full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// Check if buffer is empty
int isEmpty() {
    return (front == -1);
}

// Add message to buffer
void addMessage(char msg[]) {
    if (isFull()) {
        printf("Chat Buffer Full! Message dropped.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    strcpy(chatBuffer[rear], msg);

    printf("Message added to chat buffer.\n");
}

// Read message from buffer
void readMessage() {
    if (isEmpty()) {
        printf("No messages in buffer.\n");
        return;
    }

    printf("Reading Message: %s\n", chatBuffer[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display all messages
void displayBuffer() {
    if (isEmpty()) {
        printf("Chat buffer is empty.\n");
        return;
    }

    printf("\nChat Buffer Messages:\n");
    int i = front;
    while (1) {
        printf("- %s\n", chatBuffer[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int choice;
    char msg[MSG_SIZE];

    do {
        printf("\n--- Online Chat Buffer System ---\n");
        printf("1. Add Message\n");
        printf("2. Read Message\n");
        printf("3. Display Chat Buffer\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // clear buffer

        switch (choice) {
            case 1:
                printf("Enter message: ");
                fgets(msg, MSG_SIZE, stdin);
                msg[strcspn(msg, "\n")] = 0;
                addMessage(msg);
                break;

            case 2:
                readMessage();
                break;

            case 3:
                displayBuffer();
                break;

            case 4:
                printf("Exiting Chat Buffer System...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
