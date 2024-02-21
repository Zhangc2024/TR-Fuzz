#include <stdio.h>
int main()
{
    /*int a=10, b=20, c=30, d=40, e=50;
    
	printf("a=%x b=%x c=%x d=%x e=%x", &a, &b, &c, &d, 
	&e);*/
	
	int sonlar[5]={5,-10,8,3,7};
	printf("sonlar[0]=%d\n", sonlar[0]);
	printf("sonlar[1]=%d\n", sonlar[1]);
	printf("sonlar[2]=%d\n", sonlar[2]);
	printf("sonlar[3]=%d\n", sonlar[3]);
	printf("sonlar[4]=%d\n", sonlar[4]);
	
	int a[]={1,2,3,4,5,6,7,8,9};
	printf("%d\n", sizeof(a));
	int numbers[5]={1,9};
	printf("numbers[0]=%d\n", numbers[0]);
	printf("numbers[1]=%d\n", numbers[1]);
	printf("numbers[2]=%d\n", numbers[2]);
	printf("numbers[3]=%d\n", numbers[3]);
	printf("numbers[4]=%d\n", numbers[4]);
	
    return 0;
}