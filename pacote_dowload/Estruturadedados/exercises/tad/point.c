/*
Add new information to the TAD point, such as adding and subtracting points.
Additionally, add a possible representation of the point in polar coordinates.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    float x;
    float y;
};

typedef struct Point point;

point *create_point(float x, float y) {
    point* p = (point*) malloc(sizeof(point));
    p->x = x;
    p->y = y;
    return p;
}

void to_polar(point* p, float* r, float* theta) {
    *r = sqrt(p->x * p->x + p->y * p->y);
    *theta = atan2(p->y, p->x);
}

void free_point(point* p) {
    free(p);
}

point* add_points(point* p1, point* p2) {
    return create_point(p1->x + p2->x, p1->y + p2->y);
}

point* subtract_points(point* p1, point* p2) {
    return create_point(p1->x - p2->x, p1->y - p2->y);
}

float distance(point* p1, point* p2) {
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

int main() {
    point* p1 = create_point(1, 2);
    point* p2 = create_point(3, 4);

    point* p3 = add_points(p1, p2);
    point* p4 = subtract_points(p1, p2);

    printf("Distance between p1 and p2: %.2f\n", distance(p1, p2));
    printf("Distance between p1 and p3: %.2f\n", distance(p1, p3));
    printf("Distance between p1 and p4: %.2f\n", distance(p1, p4));

    free_point(p1);
    free_point(p2);
    free_point(p3);
    free_point(p4);

    return 0;
}