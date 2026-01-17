#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 300

const char *sentences[] = {
    "C programming is powerful and fast",
    "Practice typing to increase your speed",
    "Learning programming improves logic",
    "Typing speed test using C language",
    "Hard work always leads to success"
};

int main() {
    char input[MAX];
    int choice;
    srand(time(NULL));

    int index = rand() % 5;
    const char *text = sentences[index];

    printf("\n⌨️ Typing Speed Test Program\n");
    printf("\nType the following sentence:\n\n");
    printf("--------------------------------------------------\n");
    printf("%s\n", text);
    printf("--------------------------------------------------\n\n");

    printf("Press ENTER when ready...");
    getchar();

    time_t start = time(NULL);

    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = 0;

    time_t end = time(NULL);

    double timeTaken = difftime(end, start);

    int correctChars = 0;
    int len = strlen(text);

    for(int i = 0; i < len && i < strlen(input); i++) {
        if(text[i] == input[i])
            correctChars++;
    }

    int words = len / 5;
    double wpm = (words / timeTaken) * 60;

    printf("\n⏱ Time Taken: %.2f seconds\n", timeTaken);
    printf("✔ Correct Characters: %d / %d\n", correctChars, len);
    printf("📈 Accuracy: %.2f%%\n", ((float)correctChars / len) * 100);
    printf("🚀 Typing Speed: %.2f WPM\n", wpm);

    return 0;
}
