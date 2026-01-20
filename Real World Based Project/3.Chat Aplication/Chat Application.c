#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER 1024

int main() {
    int sock;
    struct sockaddr_in server;
    char message[BUFFER], reply[BUFFER];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Socket creation failed\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Connection failed\n");
        return 1;
    }

    printf("Connected to server...\n");

    while(1) {
        printf("You: ");
        fgets(message, BUFFER, stdin);

        // Send message
        send(sock, message, strlen(message), 0);

        // Exit condition
        if(strncmp(message, "exit", 4) == 0)
            break;

        // Receive reply
        recv(sock, reply, BUFFER, 0);
        printf("Server: %s\n", reply);
    }

    close(sock);
    return 0;
}
