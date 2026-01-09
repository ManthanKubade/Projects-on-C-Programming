#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Voter {
    int voterID;
    int hasVoted;
};

void registerVoter() {
    struct Voter v;
    FILE *fp = fopen("voters.dat", "ab");

    printf("\nEnter Voter ID: ");
    scanf("%d", &v.voterID);
    v.hasVoted = 0;

    fwrite(&v, sizeof(v), 1, fp);
    fclose(fp);

    printf("Voter Registered Successfully!\n");
}

int checkVoter(int id) {
    struct Voter v;
    FILE *fp = fopen("voters.dat", "rb");

    while (fread(&v, sizeof(v), 1, fp)) {
        if (v.voterID == id) {
            fclose(fp);
            return v.hasVoted;
        }
    }
    fclose(fp);
    return -1;
}

void updateVoteStatus(int id) {
    struct Voter v;
    FILE *fp = fopen("voters.dat", "rb+");

    while (fread(&v, sizeof(v), 1, fp)) {
        if (v.voterID == id) {
            v.hasVoted = 1;
            fseek(fp, -sizeof(v), SEEK_CUR);
            fwrite(&v, sizeof(v), 1, fp);
            break;
        }
    }
    fclose(fp);
}

void castVote() {
    int id, choice;
    FILE *fp = fopen("votes.dat", "a");

    printf("\nEnter Voter ID: ");
    scanf("%d", &id);

    int status = checkVoter(id);

    if (status == -1) {
        printf("Voter not registered!\n");
        return;
    }
    if (status == 1) {
        printf("You have already voted!\n");
        return;
    }

    printf("\n1. Candidate A\n2. Candidate B\n3. Candidate C\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    fprintf(fp, "%d\n", choice);
    fclose(fp);

    updateVoteStatus(id);

    printf("Vote Cast Successfully!\n");
}

void showResult() {
    int vote, a=0, b=0, c=0;
    FILE *fp = fopen("votes.dat", "r");

    while (fscanf(fp, "%d", &vote) != EOF) {
        if (vote == 1) a++;
        else if (vote == 2) b++;
        else if (vote == 3) c++;
    }
    fclose(fp);

    printf("\n--- Election Result ---\n");
    printf("Candidate A: %d votes\n", a);
    printf("Candidate B: %d votes\n", b);
    printf("Candidate C: %d votes\n", c);
}

int main() {
    int choice;

    while (1) {
        printf("\n\n--- Online Voting System ---\n");
        printf("1. Register Voter\n");
        printf("2. Cast Vote\n");
        printf("3. View Result (Admin)\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: registerVoter(); break;
            case 2: castVote(); break;
            case 3: showResult(); break;
            case 4: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
    return 0;
}
