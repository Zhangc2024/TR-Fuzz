#include <stdio.h>

#define max(A, B) ((A) > (B) ? (A): (B))

int main() {
    printf("max(5, 4) = %d\n", max(5,4));
    return 0;
}
