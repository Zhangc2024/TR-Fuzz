# include <stdio.h>
/*the expression ++n increments n before its value is used,
while n++ increments n after its value has been used*/
main(){
    int n, m;
    n = 3;
    m = 7;
    printf("The number of ++n is %d\n", ++n);
    printf("Now the value of n is %d\n", n);
    printf("The number of m++ is %d\n", m++);
    printf("Now the value of m is %d\n", m);
}
