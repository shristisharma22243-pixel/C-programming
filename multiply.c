#include <stdio.h>

int main() {
    int num1, num2, product;

    // Input two numbers
    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    // Multiply the numbers
    product = num1 * num2;

    // Display the result
    printf("Product = %d\n", product);

    return 0;
}