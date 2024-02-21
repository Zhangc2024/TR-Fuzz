#include <stdio.h>

void insertsort(int v[], int n){
    int i, j, temp;
    for (i = 0; i < n; i++)
    for (j = i; j>=0 && v[j] > v[j+1]; j-=1){
        temp = v[j];
        v[j] = v[j+1];
        v[j+1] = temp;
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
    insertsort(a, 6);
    listarr(a, 6);
}
