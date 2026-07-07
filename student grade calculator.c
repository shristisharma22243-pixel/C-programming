#include <stdio.h>

int main() {
    int s1, s2, s3, s4, s5;
    int total;
    float percentage;

    // Input marks
    printf("Enter marks for Subject 1: ");
    scanf("%d", &s1);

    printf("Enter marks for Subject 2: ");
    scanf("%d", &s2);

    printf("Enter marks for Subject 3: ");
    scanf("%d", &s3);

    printf("Enter marks for Subject 4: ");
    scanf("%d", &s4);

    printf("Enter marks for Subject 5: ");
    scanf("%d", &s5);

    // Calculate total and percentage
    total = s1 + s2 + s3 + s4 + s5;
    percentage = total / 5.0;

    // Display result
    printf("\n----- Result -----\n");
    printf("Total Marks = %d\n", total);
    printf("Percentage = %.2f%%\n", percentage);

    // Grade calculation
    if (percentage >= 90)
        printf("Grade = A+\n");
    else if (percentage >= 80)
        printf("Grade = A\n");
    else if (percentage >= 70)
        printf("Grade = B\n");
    else if (percentage >= 60)
        printf("Grade = C\n");
    else if (percentage >= 50)
        printf("Grade = D\n");
    else
        printf("Grade = F (Fail)\n");

    return 0;
}