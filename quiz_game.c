#include <stdio.h>
#include <ctype.h>

int main()
{
    char answer;
    int score = 0;

    printf("=====================================\n");
    printf("       WELCOME TO QUIZ GAME\n");
    printf("=====================================\n\n");

    // Question 1
    printf("Q1. What is the capital of India?\n");
    printf("A. Mumbai\nB. Delhi\nC. Kolkata\nD. Chennai\n");
    printf("Enter Answer: ");
    scanf(" %c", &answer);
while(getchar() != '\n');

    if (toupper(answer) == 'B')
        score++;

    // Question 2
    printf("\nQ2. Which language is used for system programming?\n");
    printf("A. C\nB. HTML\nC. CSS\nD. SQL\n");
    printf("Enter Answer: ");
    scanf(" %c", &answer);
while(getchar() != '\n');

    if (toupper(answer) == 'A')
        score++;

    // Question 3
    printf("\nQ3. Who invented C language?\n");
    printf("A. Dennis Ritchie\nB. James Gosling\nC. Bjarne Stroustrup\nD. Guido van Rossum\n");
    printf("Enter Answer: ");
scanf(" %c", &answer);
while(getchar() != '\n');

    if (toupper(answer) == 'A')
        score++;

    // Question 4
    printf("\nQ4. Which symbol is used for comments in C?\n");
    printf("A. //\nB. ##\nC. <!-- -->\nD. **\n");
    printf("Enter Answer: ");
    scanf(" %c", &answer);
while(getchar() != '\n');

    if (toupper(answer) == 'A')
        score++;

    // Question 5
    printf("\nQ5. Which header file is used for printf()?\n");
    printf("A. string.h\nB. math.h\nC. stdio.h\nD. stdlib.h\n");
    printf("Enter Answer: ");
    scanf(" %c", &answer);
while(getchar() != '\n');

    if (toupper(answer) == 'C')
        score++;

    // Question 6
    printf("\nQ6. Which loop executes at least once?\n");
    printf("A. for\nB. while\nC. do-while\nD. None\n");
    printf("Enter Answer: ");
    scanf(" %c", &answer);
while(getchar() != '\n');

    if (toupper(answer) == 'C')
        score++;

    // Question 7
    printf("\nQ7. What is the size of int (commonly)?\n");
    printf("A. 1 Byte\nB. 2 Bytes\nC. 4 Bytes\nD. 8 Bytes\n");
    printf("Enter Answer: ");
    scanf(" %c", &answer);
while(getchar() != '\n');

    if (toupper(answer) == 'C')
        score++;

    // Question 8
    printf("\nQ8. Which operator is used for logical AND?\n");
    printf("A. &\nB. &&\nC. ||\nD. !\n");
    printf("Enter Answer: ");
    scanf(" %c", &answer);
while(getchar() != '\n');

    if (toupper(answer) == 'B')
        score++;

    // Question 9
    printf("\nQ9. Which keyword is used to exit a loop?\n");
    printf("A. continue\nB. stop\nC. break\nD. exit\n");
    printf("Enter Answer: ");
    scanf(" %c", &answer);
while(getchar() != '\n');

    if (toupper(answer) == 'C')
        score++;

    // Question 10
    printf("\nQ10. Which function is used to read formatted input?\n");
    printf("A. printf()\nB. scanf()\nC. gets()\nD. puts()\n");
    printf("Enter Answer: ");
    scanf(" %c", &answer);
while(getchar() != '\n');

    if (toupper(answer) == 'B')
        score++;

    printf("\n=====================================\n");
    printf("           QUIZ RESULT\n");
    printf("=====================================\n");

    printf("Correct Answers : %d/10\n", score);
    printf("Percentage      : %.2f%%\n", score * 10.0);

    if(score >= 8)
        printf("Excellent! 🌟\n");
    else if(score >= 5)
        printf("Good Job! 👍\n");
    else
        printf("Keep Practicing! 😊\n");

    return 0;
}