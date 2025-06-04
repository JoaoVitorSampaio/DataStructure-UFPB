/*
Consider a structure to represent a point in 2D space and implement a function that indicates whether a given point p is located inside or outside a rectangle.
The section is defined by its lower left v1 and upper right v2 vertices.
The function must return 1 if the point is located inside the rectangle, and 0 otherwise.
*/

#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rectangle {
    struct point lower_left;
    struct point upper_right;
};

int is_inside(struct point p, struct rectangle r) {
    return (p.x >= r.lower_left.x && p.x <= r.upper_right.x && p.y >= r.lower_left.y && p.y <= r.upper_right.y);
}

int main() {
    struct point p;
    struct rectangle r;

    // request for input
    printf("LOWER LEFT VERTEX\n");
    printf("Enter x0: ");
    scanf("%d", &r.lower_left.x);
    printf("Enter y0: ");
    scanf("%d", &r.lower_left.y);

    printf("UPPER RIGHT VERTEX\n");
    printf("Enter x1: ");
    scanf("%d", &r.upper_right.x);
    printf("Enter x2: ");
    scanf("%d", &r.upper_right.y);

    printf("POINT\n");
    printf("Enter x: ");
    scanf("%d", &p.x);
    printf("Enter y: ");
    scanf("%d", &p.y);

    // output
    if (is_inside(p, r)) {
        printf("The point is inside the rectangle\n");
    }
    else {
        printf("The point is outside the rectangle\n");
    }
}