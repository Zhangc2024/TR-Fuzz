#include <stdio.h>

void swap(int*, int*);

int main(){
    int m = 20, n = 10;
    printf("Before swapping:\nm = %d, n = %d\n", m, n);
    swap(&m, &n);
    printf("After swapping:\nm = %d, n = %d\n", m, n);
    
}

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
