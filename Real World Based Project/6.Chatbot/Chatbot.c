#include <stdio.h>
#include <string.h>

void chatbot(char input[]) {

    if (strstr(input, "hi") || strstr(input, "hello"))
        printf("Bot: Hello! How can I help you?\n");

    else if (strstr(input, "how are you"))
        printf("Bot: I'm doing great! What about you?\n");

    else if (strstr(input, "your name"))
        printf("Bot: I am a rule-based chatbot.\n");

    else if (strstr(input, "help"))
        printf("Bot: Sure! Tell me your problem.\n");

    else if (strstr(input, "bye"))
        printf("Bot: Goodbye! Have a nice day.\n");

    else
        printf("Bot: Sorry, I don't understand.\n");
}

int main() {
    char input[100];

    printf("Rule-Based Chatbot (type 'bye' to exit)\n");

    while(1) {
        printf("\nYou: ");
        fgets(input, sizeof(input), stdin);

        // Remove newline
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "bye") == 0) {
            printf("Bot: Goodbye!\n");
            break;
        }

        chatbot(input);
    }

    return 0;
}
