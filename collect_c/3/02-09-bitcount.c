#include <stdio.h>
int bitcount(unsigned x){
    int b;
    int i;
    i = 0;

    while (x > 0){
        x &= (x-1);
        i += 1;
    }
    return i;
}

main(){
   printf ("%d", bitcount(55));
}
