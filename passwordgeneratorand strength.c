#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void generatePassword(char password[], int length)
{
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char digit[] = "0123456789";
    char special[] = "@#$%&*!?";

    char all[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@#$%&*!?";

    int size = strlen(all);

    for(int i = 0; i < length; i++)
    {
        password[i] = all[rand() % size];
    }

    password[length] = '\0';
}

void checkStrength(char password[])
{
    int upper = 0, lower = 0, digit = 0, special = 0;
    int score = 0;

    int len = strlen(password);

    for(int i = 0; i < len; i++)
    {
        if(isupper(password[i]))
            upper = 1;
        else if(islower(password[i]))
            lower = 1;
        else if(isdigit(password[i]))
            digit = 1;
        else
            special = 1;
    }

    score = upper + lower + digit + special;

    if(len >= 8)
        score++;

    printf("\nPassword Length : %d\n", len);

    if(score == 5)
        printf("Password Strength : Very Strong\n");
    else if(score == 4)
        printf("Password Strength : Strong\n");
    else if(score == 3)
        printf("Password Strength : Medium\n");
    else
        printf("Password Strength : Weak\n");
}

int main()
{
    int choice, length;
    char password[100];

    srand(time(NULL));

    while(1)
    {
        printf("\n==============================");
        printf("\n PASSWORD TOOL");
        printf("\n==============================");
        printf("\n1. Generate Password");
        printf("\n2. Check Password Strength");
        printf("\n3. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Password Length: ");
                scanf("%d", &length);

                if(length <= 0 || length > 50)
                {
                    printf("Invalid Length!\n");
                }
                else
                {
                    generatePassword(password, length);
                    printf("\nGenerated Password: %s\n", password);
                }
                break;

            case 2:
                printf("Enter Password: ");
                scanf("%s", password);

                checkStrength(password);
                break;

            case 3:
                printf("\nProgram Ended.\n");
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}