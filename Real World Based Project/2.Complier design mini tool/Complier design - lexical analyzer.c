#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char word[]) {
    char keywords[10][10] = {
        "int","float","if","else","while","for","return","char","double","void"
    };

    for(int i = 0; i < 10; i++) {
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[100], token[20];
    int i = 0, j = 0;

    printf("Enter a line of code:\n");
    fgets(input, sizeof(input), stdin);

    printf("\nTokens:\n");

    while(input[i] != '\0') {

        // Skip spaces
        if(isspace(input[i])) {
            i++;
            continue;
        }

        // Identifier or Keyword
        if(isalpha(input[i])) {
            j = 0;
            while(isalnum(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';

            if(isKeyword(token))
                printf("Keyword: %s\n", token);
            else
                printf("Identifier: %s\n", token);
        }

        // Number
        else if(isdigit(input[i])) {
            j = 0;
            while(isdigit(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("Number: %s\n", token);
        }

        // Operator
        else if(strchr("+-*/=%", input[i])) {
            printf("Operator: %c\n", input[i]);
            i++;
        }

        // Special Symbol
        else {
            printf("Special Symbol: %c\n", input[i]);
            i++;
        }
    }

    return 0;
}
