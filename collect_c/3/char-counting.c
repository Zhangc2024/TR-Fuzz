#include<stdio.h>

int main(){
    double nc;
    /* C requires that a for-loop must have a body.
     * the isoloated semicolon is there to satisfy this condition */
    for(nc = 0 ; getchar() != EOF ; ++nc)
        ;
    printf("%.0f\n", nc);
    /* printf uses %f for both floats and doubles.
     * we use .0f here to suppress the decimal part*/
    return 0;
}
