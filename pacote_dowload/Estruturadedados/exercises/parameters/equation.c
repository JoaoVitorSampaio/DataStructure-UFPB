/*
Implement a function that calculates the roots of a quadratic equation, like ax²+bx+c=0.
This function must have as its return value the number of real and distinct roots of the equation.
If there are real roots, their values must be stored in the variables indicated by x1 and x2.
*/

// include the necessary libraries
#include <stdio.h>
#include <math.h>

// function that calculates the roots of a quadratic equation
int roots (float a, float b, float c, float *x1, float *x2) {
    float delta = b*b - 4*a*c;
    if (delta < 0) {
        return 0;
    }
    else if (delta == 0) {
        *x1 = -b / (2*a);
        return 1;
    }
    else {
        *x1 = (-b + sqrt(delta)) / (2*a);
        *x2 = (-b - sqrt(delta)) / (2*a);
        return 2;
    }
}

int main() {
    // declare the variables
    float a, b, c, x1, x2;
    int n;

    // read the values of a, b and c
    printf("EQUATION: ax^2 + bx + c = 0\n");
    printf("Enter the value of a: ");
    scanf("%f", &a);
    printf("Enter the value of b: ");
    scanf("%f", &b);
    printf("Enter the value of c: ");
    scanf("%f", &c);

    // call the function roots
    n = roots(a, b, c, &x1, &x2);
    if (n == 0) {
        printf("The equation has no real roots.\n");
    }
    else if (n == 1) {
        printf("The equation has one real root: x = %.2f\n", x1);
    }
    else {
        printf("The equation has two real roots: x1 = %.2f and x2 = %.2f\n", x1, x2);
    }

    return 0;
}