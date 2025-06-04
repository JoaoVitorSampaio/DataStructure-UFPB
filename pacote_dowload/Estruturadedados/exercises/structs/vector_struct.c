/*
Consider a structure to represent a vector in 3D space and implement a function that calculates the dot product of two vectors.
*/

#include <stdio.h>

struct vector {
    float x;
    float y;
    float z;
};

float dot_product(struct vector a, struct vector b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

int main() {
    struct vector a, b;

    // read vectors
    printf("Enter vector a (x, y, z): ");
    scanf("%f %f %f", &a.x, &a.y, &a.z);
    printf("Enter vector b (x, y, z): ");
    scanf("%f %f %f", &b.x, &b.y, &b.z);

    // calculate and print dot product
    printf("Dot product: %.2f\n", dot_product(a, b));

    return 0;
}