/*
Implement a function that calculates the derivative of a polynomial.
   Each monomial term is represented as exemplified in the previous example.
   The output is a vector (dimension degree) where the function stores the coefficients of the polynomial resulting from the derivative.
*/

#include <stdio.h>
#include <stdlib.h>

void derivative(double *poly, int degree, double *out) {
    // Compute the derivative coefficients
    for (int i = 0; i < degree; i++) {
        out[i] = poly[i + 1] * (i + 1);
    }

    // Print the derived polynomial coefficients
    printf("Derivative coefficients:\n");
    for (int i = 0; i < degree; i++) {
        printf("Coefficient of x^%d: %.2f\n", i, out[i]);
    }
}

int main() {
    int degree;

    // Ask the user for the degree of the polynomial
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    // Allocate memory for the polynomial coefficients
    double *polynomial = (double *)malloc((degree + 1) * sizeof(double));
    if (polynomial == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Ask the user for the polynomial coefficients
    for (int i = 0; i <= degree; i++) {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%lf", &polynomial[i]);
    }

    // Allocate memory to store the derivative coefficients
    double *out = (double *)malloc(degree * sizeof(double));
    if (out == NULL) {
        printf("Memory allocation failed.\n");
        free(polynomial);
        return 1;
    }

    // Call the derivative function
    derivative(polynomial, degree, out);

    // Free allocated memory
    free(polynomial);
    free(out);

    return 0;
}