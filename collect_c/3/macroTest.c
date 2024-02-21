#include <stdio.h>
#define max(A, B) ((A) > (B) ? (A) : (B))
#define square(x) x * x

int main () {
    int i = 3, j = 2, z = 5;
    printf("i: %d, j: %d, max(i++, j++): %d, i again:%d\n", i, j, max(i++, j++), i);
    printf("z: %d, square(z+1): %d\n", z, square(z+1));
    return 0;
}
