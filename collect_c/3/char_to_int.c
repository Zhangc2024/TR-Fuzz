#include<stdio.h>
#include<stdlib.h>

/* a char is just a small integer
 * so chars may be free used in arithmetic operations
 *
 * atoi from stdlib.h takes a string representation of an integer
 * and returns the int equivalent
 *
 * Remember: C has no strings, it uses char[] to hold strings
 * */
int convert(char a){
    // return numeric value of a digit
    return a -'0';
}
int main(){
    int i;
    char a[10] = "100";
    char c[5] = {'1', '2', '3', '4', '5'};

    printf("using char -'0' \n");
    for(i = 0; i < 5; i++)
        printf("%d\n", convert(c[i]));

    /* using atoi */
    printf("using atoi from stdlib.h %d \n", atoi(a));

    //for(i = 0; i < 5; i++)
    //   printf("%d\n", atoi(&c[i]));
}
