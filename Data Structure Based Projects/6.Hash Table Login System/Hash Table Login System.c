#include <stdio.h>
#include <string.h>

#define SIZE 10

struct User {
    char username[20];
    char password[20];
};

struct User table[SIZE];

int hash(char *key) {
    int sum = 0;
    for (int i = 0; key[i]; i++)
        sum += key[i];
    return sum % SIZE;
}

void registerUser(char *u, char *p) {
    int index = hash(u);
    strcpy(table[index].username, u);
    strcpy(table[index].password, p);
    printf("User registered successfully!\n");
}

void login(char *u, char *p) {
    int index = hash(u);
    if (strcmp(table[index].username, u) == 0 &&
        strcmp(table[index].password, p) == 0)
        printf("Login successful!\n");
    else
        printf("Invalid login!\n");
}

int main() {
    registerUser("admin", "1234");
    registerUser("user", "pass");

    login("admin", "1234");
    login("user", "wrong");

    return 0;
}
