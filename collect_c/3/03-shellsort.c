#include <stdio.h>
/* shellsort: sort v[]...v[n-1] into increasing order */

void shellsort(int v[], int n) {
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /=2)
        for (i = gap; i < n; i++)
        for (j = i-gap; j >= 0 && v[j]>v[j+gap]; j-=gap){
            temp = v[j];
            v[j] = v[j+gap];
            v[j+gap] = temp;
        }
}

void listarr(int a[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf ("%d ", a[i]);
    }
    printf ("\n");
}

main(){
    int a[]={3,2,4,11,5,7};
    listarr(a, 6);
    shellsort(a, 6);
    listarr(a, 6);
}
