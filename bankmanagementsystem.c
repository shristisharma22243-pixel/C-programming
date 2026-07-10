#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Account {
    int accNo;
    char name[50];
    float balance;
};

struct Account bank[MAX];
int totalAccounts = 0;

// Create Account
void createAccount() {
    if (totalAccounts >= MAX) {
        printf("\nBank is Full!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d", &bank[totalAccounts].accNo);

    printf("Enter Customer Name: ");
    scanf(" %[^\n]", bank[totalAccounts].name);

    printf("Enter Initial Deposit: ");
    scanf("%f", &bank[totalAccounts].balance);

    totalAccounts++;

    printf("\nAccount Created Successfully!\n");
}

// Find Account
int findAccount(int accNo) {
    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accNo == accNo)
            return i;
    }
    return -1;
}

// Deposit
void deposit() {
    int accNo;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    int index = findAccount(accNo);

    if (index == -1) {
        printf("Account Not Found!\n");
        return;
    }

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    bank[index].balance += amount;

    printf("Deposit Successful!\n");
}

// Withdraw
void withdraw() {
    int accNo;
    float amount;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    int index = findAccount(accNo);

    if (index == -1) {
        printf("Account Not Found!\n");
        return;
    }

    printf("Enter Withdrawal Amount: ");
    scanf("%f", &amount);

    if (amount > bank[index].balance) {
        printf("Insufficient Balance!\n");
        return;
    }

    bank[index].balance -= amount;

    printf("Withdrawal Successful!\n");
}

// Check Balance
void checkBalance() {
    int accNo;

    printf("\nEnter Account Number: ");
    scanf("%d", &accNo);

    int index = findAccount(accNo);

    if (index == -1) {
        printf("Account Not Found!\n");
        return;
    }

    printf("\nAccount Number : %d", bank[index].accNo);
    printf("\nCustomer Name  : %s", bank[index].name);
    printf("\nBalance        : %.2f\n", bank[index].balance);
}

// Display All Accounts
void displayAccounts() {
    if (totalAccounts == 0) {
        printf("\nNo Accounts Found!\n");
        return;
    }

    printf("\n------------------------------------------------------");
    printf("\nAcc No\tCustomer Name\t\tBalance");
    printf("\n------------------------------------------------------");

    for (int i = 0; i < totalAccounts; i++) {
        printf("\n%d\t%-20s\t%.2f",
               bank[i].accNo,
               bank[i].name,
               bank[i].balance);
    }

    printf("\n------------------------------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n==============================");
        printf("\n BANK MANAGEMENT SYSTEM");
        printf("\n==============================");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Display All Accounts");
        printf("\n6. Exit");
        printf("\nEnter Choice: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                createAccount();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                checkBalance();
                break;

            case 5:
                displayAccounts();
                break;

            case 6:
                printf("\nThank You!\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}