/*
Implement a function that indicates whether a point (x,y) is located inside or outside a rectangle.
The rectangle is defined by its lower left (x0,y0) and upper right (x1,y1) vertices.
The function must have a return value of 1, if the point is inside the rectangles, and O otherwise.
*/

#include <stdio.h>

int is_inside(int x, int y, int x0, int y0, int x1, int y1){
    return (x >= x0 && x <= x1 && y >= y0 && y <= y1);
}

int main(){
    int x, y, x0, y0, x1, y1; // variable declarations

    // request for input

    printf("LOWER LEFT VERTEX\n");
    printf("Enter x0: ");
    scanf("%d", &x0);
    printf("Enter y0: ");
    scanf("%d", &y0);

    printf("UPPER RIGHT VERTEX\n");
    printf("Enter x1: ");
    scanf("%d", &x1);
    printf("Enter y1: ");
    scanf("%d", &y1);

    printf("POINT\n");
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);

    // output
    if (is_inside(x, y, x0, y0, x1, y1)) {
        printf("The point is inside the rectangle\n");
    }
    else {
        printf("The point is outside the rectangle\n");
    }

    return 0;
}
