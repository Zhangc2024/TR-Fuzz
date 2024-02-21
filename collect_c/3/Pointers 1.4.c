#include <stdio.h>
#include <stdlib.h>
void polinominal(int a,int b,int c, int *xPtr);

main(){
	int a,b,c,x;
	a=rand();
	b=rand();
	c=rand();
	x=rand();
	printf("a = %d, b = %d, c = %d and x = %d\n",a,b,c,x);
	polinominal(a,b,c,&x);
	printf("After funtion called\n");
	printf("a = %d, b = %d, c = %d and x = %d",a,b,c,x);
	
	
}
void polinominal(int a,int b,int c, int *xPtr){
	*xPtr=a**xPtr**xPtr+b**xPtr+c;
}
