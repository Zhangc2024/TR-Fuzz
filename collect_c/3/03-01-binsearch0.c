#include <stdio.h>

int binsearch(int x, int v[], int n){

    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while ( low <= high ){
        printf ("%d %d \n", mid , v[mid]);
        if ( v[mid] > x ){
            high = mid - 1;
        } else if ( v[mid] < x){
            low = mid + 1;
        } else {
            return mid;
        }
        mid = (low + high) / 2;
    }

    return -1;
}

main(){
     int a[5];
     int b;
     a[0] = 1;
     a[1] = 2;
     a[2] = 4;
     a[3] = 8;
     a[4] = 16;
     a[5] = 19;
     b = 19;

     printf ( "-- %d", binsearch(b, a, 6) );
}
