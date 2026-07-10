#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

struct Candidate {
    char name[50];
    int votes;
};

struct Candidate candidates[MAX_CANDIDATES];
char votedIDs[MAX_VOTERS][20];

int candidateCount = 0;
int voterCount = 0;

// Check if voter already voted
int hasVoted(char id[]) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(votedIDs[i], id) == 0)
            return 1;
    }
    return 0;
}

// Add Candidate
void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("\nMaximum candidates reached!\n");
        return;
    }

    printf("Enter Candidate Name: ");
    scanf(" %[^\n]", candidates[candidateCount].name);
    candidates[candidateCount].votes = 0;
    candidateCount++;

    printf("Candidate Added Successfully!\n");
}

// Display Candidates
void displayCandidates() {
    printf("\n----- Candidate List -----\n");

    if (candidateCount == 0) {
        printf("No Candidates Available!\n");
        return;
    }

    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// Vote
void vote() {
    char voterID[20];
    int choice;

    if (candidateCount == 0) {
        printf("No Candidates Available!\n");
        return;
    }

    printf("\nEnter Voter ID: ");
    scanf("%s", voterID);

    if (hasVoted(voterID)) {
        printf("You have already voted!\n");
        return;
    }

    displayCandidates();

    printf("Enter Candidate Number: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > candidateCount) {
        printf("Invalid Candidate!\n");
        return;
    }

    candidates[choice - 1].votes++;

    strcpy(votedIDs[voterCount], voterID);
    voterCount++;

    printf("Vote Cast Successfully!\n");
}

// Result
void result() {
    printf("\n===== Election Results =====\n");

    if (candidateCount == 0) {
        printf("No Candidates!\n");
        return;
    }

    int winner = 0;

    for (int i = 0; i < candidateCount; i++) {
        printf("%s : %d Votes\n",
               candidates[i].name,
               candidates[i].votes);

        if (candidates[i].votes > candidates[winner].votes)
            winner = i;
    }

    printf("\nWinner: %s\n", candidates[winner].name);
}

// Admin Login
int adminLogin() {
    char user[20], pass[20];

    printf("\nAdmin Username: ");
    scanf("%s", user);

    printf("Admin Password: ");
    scanf("%s", pass);

    if (strcmp(user, "admin") == 0 &&
        strcmp(pass, "1234") == 0)
        return 1;

    return 0;
}

int main() {
    int choice;

    while (1) {
        printf("\n============================");
        printf("\n ONLINE VOTING SYSTEM");
        printf("\n============================");
        printf("\n1. Admin Login");
        printf("\n2. Vote");
        printf("\n3. Display Candidates");
        printf("\n4. Election Result");
        printf("\n5. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            if (adminLogin()) {
                int ch;
                do {
                    printf("\n----- Admin Panel -----");
                    printf("\n1. Add Candidate");
                    printf("\n2. Back");
                    printf("\nChoice: ");
                    scanf("%d", &ch);

                    switch (ch) {
                    case 1:
                        addCandidate();
                        break;
                    case 2:
                        break;
                    default:
                        printf("Invalid Choice!\n");
                    }

                } while (ch != 2);
            } else {
                printf("Invalid Login!\n");
            }
            break;

        case 2:
            vote();
            break;

        case 3:
            displayCandidates();
            break;

        case 4:
            result();
            break;

        case 5:
            printf("\nThank You!\n");
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}