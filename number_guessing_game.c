#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;

    // Generate a random number between 1 and 100
    srand(time(0));
    number = rand() % 100 + 1;

    printf("=================================\n");
    printf("    NUMBER GUESSING GAME\n");
    printf("=================================\n");
    printf("I have chosen a number between 1 and 100.\n");
    printf("Try to guess it!\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess > number) {
            printf("Too High! Try Again.\n\n");
        }
        else if (guess < number) {
            printf("Too Low! Try Again.\n\n");
        }
        else {
            printf("\nCongratulations! You guessed the correct number.\n");
            printf("You guessed it in %d attempts.\n", attempts);
        }

    } while (guess != number);

    return 0;
}