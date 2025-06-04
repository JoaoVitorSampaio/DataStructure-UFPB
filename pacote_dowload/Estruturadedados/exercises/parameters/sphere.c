/*
Implement a function that calculates the surface area and volume of a sphere of radius r.
The surface area and volume are given, respectively, by 4r² and 4r³/3.
*/

// include the necessary libraries
#include <stdio.h>
#include <math.h>

// function to calculate the surface area and volume of a sphere
void calc_sphere(float r, float *area, float *volume) {
    *area = 4 * pow(r, 2);
    *volume = 4 * pow(r, 3) / 3;
}

int main() {
    // declare variables
    float r, area, volume;

    // read the radius of the sphere
    printf("Enter the radius of the sphere: ");
    scanf("%f", &r);

    // calculate the surface area and volume of the sphere
    calc_sphere(r, &area, &volume);

    // print the results
    printf("The surface area of the sphere is %.2f\n", area);
    printf("The volume of the sphere is %.2f\n", volume);

    return 0;
}