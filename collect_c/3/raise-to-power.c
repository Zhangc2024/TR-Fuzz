#include<stdio.h>

int power(int base, int xp);

int main(){
    int i;
    for (i = 0; i < 10; i++){
        printf("%d %d %d\n", i, power(2,i), power(-3, i));
    }
    return 0;
}

/* I thought that this should be a recursive problem 
 * since x^y = x * x^(y-1)
 * Naive implementation, doesn't handle negative powers
 */

int power(int base, int xp){
    if (xp < 1)
        return 1;
    else
        return base * power(base, xp - 1);
}

/* this can also be solved by using a loop as presented in K&R 
* int power(int base, int xp){
*     int prod = 1;
*     for (int i = 1; i <= xp; i++)
*         prod = prod * base; 
*     return prod;
* }
* */
