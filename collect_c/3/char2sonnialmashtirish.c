#include <stdio.h>
int main()
{
	int a, b, c;
	printf("a ni kiriting: ", a);
	scanf("%d", &a);
	printf("b ni kiriting: ", b);
	scanf("%d", &b);
	
	c=a;
	a=b;
	b=c;
	
	printf("Almashgandan so'ng: a=%d\nb=%d", a, b);
	
	return 0;
}