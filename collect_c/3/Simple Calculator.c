#include<stdio.h>
int main()
{
	int a,b,c,r;
	printf("\nEnter Two Number :");
	scanf("%d%d",&a,&b);
	printf("What You Want To Do?\n1=ADD\n2=SUBSTRACT\n3=MULTIPLY\n4=DIVISION\n5=REMAINDER\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			r=a+b;
			break;
		case 2:
			r=a-b;
			break;
		case 3:
			r=a*b;
			break;
		case 4:
			r=a/b;
			break;
		case 5:
			r=a%b;
			break;
		default:
			printf("Please Choose an option!");
			break;
	}
	printf("Result %d",r);
	return 0;
}
