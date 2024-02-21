/*WAP to print Multiplication table of a given No.*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int n,cnt;
	printf("Enter the no. whose Table is to be printed");
	scanf("%d",&n);
	cnt=1;
	while(cnt<=10)
	{
		//printf("%d\n",n*cnt);
		//        OR
		printf("%3d * %3d= %3d\n",n,cnt,n*cnt);
		cnt++;
	}
	getch();
	return 0;
}
