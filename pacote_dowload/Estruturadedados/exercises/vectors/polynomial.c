/*
Implement a function that allows the evaluation of polynomials.
Each polynomial is defined by a vector that contains its coefficients.
For example, polynomial of degree 2, 3x²+2x+12, has a vector of coefficients equal to [12,2,3].
Where the polt parameter is the vector with the polynomial coefficients, praco degree of the polynomial, ex is the value for which the polynomial should be evaluated.
*/

// libraries
#include <stdio.h>
#include <math.h>

double evaluable(int *poly, int degree, int x) {
    double result = 0;

    for (int i = 0; i <= degree; i++) {
        result += poly[i] * pow(x, i);
    }

    return result;
}

int main() {
    int degree;
    // ask the user for the degree of the polynomial
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    // create a vector to store the coefficients of the polynomial
    int polynomial[degree+1];
    // ask the user for the coefficients of the polynomial
    for (int i = 0; i <= degree; i++) {
        printf("Enter the coefficient of x^%d: ", i);
        scanf("%d", &polynomial[i]);
    }

    // ask the user for the value of x
    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);

    // call the function evaluable and print the result
    printf("The result of the polynomial is: %.2f\n", evaluable(polynomial, degree, x));

    return 0;
}