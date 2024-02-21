/* - keyword 'struct' introduces a structure declaration, which is a list of
 *   declarations enclosed in braces.
 * - An optional name called a 'structure tag' may follow the key word 'struct'
 *   (as 'point' here)
 * - the variables named in a structure are called 'members'
 */

#include<stdio.h>

#define XMAX 3200
#define YMAX 3200

struct point {
    int x;
    int y;
};

/* structures can be nested */
struct rect {
    struct point pt1;
    struct point pt2;
};

/* legal operations on a structure:
 *      - copying it
 *      - assigning to it as a unit
 *      - taking its address with '&'
 *      - accessing its members
 * structures may not be compared
 */

int main(){
    struct point pt = { 5, 10 };
    struct rect screen;
    struct point middle;
    struct point makepoint(int, int);

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
                        (screen.pt1.y + screen.pt2.y)/2);
    printf("pt(%d, %d)\n", pt.x, pt.y);
    void demostructpointer(void);
    demostructpointer();

    return 0;
}

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y){
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

/* addpoints: add two points
 * structure parameters are passed by value
 */
struct point addpoint(struct point p1, struct point p2){
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: return 1 if p in r, 0 if not
 * - convention: a rectangle includes its left and bottm sides but not its
 *   top and right sides
 * - assumes that the rectangle is presented in a standard form where pt1
 *   coordinates are less than pt2 coordinates.
 */
int ptinrect(struct point p, struct rect r){
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* the following function returns a rectangle guaranteed to be in canonical
 * form
 */

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r){
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);

    temp.pt2.x = min(r.pt1.x, r.pt2.x);
    temp.pt2.y = min(r.pt1.y, r.pt2.y);

    return temp;
}

/* - if a large structure is to be passed to a funciton, it is generally more
 *   efficient to pass a pointer than to copy the whole structure.
 *
 *          struct point *pp;
 *
 * - says that 'pp' is a pointer to a structure of type 'struct point'.
 *   if 'pp' points to a 'point' structure, '*pp' is the structure, and
 *   '(*pp).x' and '(*pp).y' are the members.
 * - Parentheses are necessary in '(*pp).x' because the precedence of the
 *   structure member operator '.' is higher than '*'
 * - The expression '*pp.x' means * (pp.x) which is illegal here because x
 *   is not a pointer
 * - Pointers to structures are so frequently used that an alternative notation
 *   is provided as a shorthand.
 *   If 'p' is a pointer to a structure, then
 *
 *          p->member-of-structure
 *   refers to the particular member.
 *  - So we could write instead
 *          printf("origin is (%d, %d)\n", pp->x, pp->y);
 */

void demostructpointer(){
    struct point origin, *pp;

    origin.x = 0;
    origin.y = 0;

    pp = &origin;
    printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);
    /* concise version */
    printf("origin is (%d, %d)\n", pp->x, pp->y);
}
