#include <stdio.h>

struct point {
    int x;
    int y;
};

// addpoint: add two points
struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

int main() {
    struct point p1 = {1, 3};
    struct point p2 = {7, 9};
    printf("p1: {%d, %d}, p2: {%d, %d}\n", p1.x, p1.y, p2.x, p2.y);

    struct point p3 = addpoint(p1, p2);
    printf("p1: {%d, %d}, p3: {%d, %d}\n", p1.x, p1.y, p3.x, p3.y);
    return 0;
}