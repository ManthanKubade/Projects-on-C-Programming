#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void backupFile();
void restoreFile();

int main() {
    int choice;

    while (1) {
        printf("\n===== FILE BACKUP SYSTEM =====\n");
        printf("1. Backup File\n");
        printf("2. Restore File\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                backupFile();
                break;
            case 2:
                restoreFile();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void backupFile() {
    FILE *source, *backup;
    char srcName[100], backupName[150];
    char ch;

    printf("Enter file name to backup: ");
    scanf("%s", srcName);

    source = fopen(srcName, "rb");
    if (source == NULL) {
        printf("File not found!\n");
        return;
    }

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    sprintf(backupName, "backup_%02d%02d%02d_%s",
            tm->tm_mday, tm->tm_mon + 1,
            tm->tm_year + 1900, srcName);

    backup = fopen(backupName, "wb");

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, backup);
    }

    fclose(source);
    fclose(backup);

    printf("Backup created successfully: %s\n", backupName);
}

void restoreFile() {
    FILE *backup, *restore;
    char backupName[100], restoreName[100];
    char ch;

    printf("Enter backup file name: ");
    scanf("%s", backupName);

    printf("Enter restore file name: ");
    scanf("%s", restoreName);

    backup = fopen(backupName, "rb");
    if (backup == NULL) {
        printf("Backup file not found!\n");
        return;
    }

    restore = fopen(restoreName, "wb");

    while ((ch = fgetc(backup)) != EOF) {
        fputc(ch, restore);
    }

    fclose(backup);
    fclose(restore);

    printf("File restored successfully!\n");
}
