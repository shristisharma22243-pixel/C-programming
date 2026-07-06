#include <stdio.h>

int main() {
    float principal, rate, time, simpleInterest;

    // Input values
    printf("Enter Principal Amount: ");
    scanf("%f", &principal);

    printf("Enter Rate of Interest: ");
    scanf("%f", &rate);

    printf("Enter Time (in years): ");
    scanf("%f", &time);

    // Calculate Simple Interest
    simpleInterest = (principal * rate * time) / 100;

    // Display result
    printf("Simple Interest = %.2f\n", simpleInterest);

    return 0;
}