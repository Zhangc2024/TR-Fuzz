#include<stdio.h>
int main()
{
	int a;
	while(a!=6)
	{
		printf("\nValue before entering if = %d",a);
		if(a==4)
		{
			printf("\nProcess Terminated");
			break;
		}
		else if(a==2)
		{
			printf("\nLoop Restarted from begining...");
			a++;
			continue;
		}
		else
		printf("\nValue After executing loop = %d",a);
		a++;
	}
	return 0;
}
