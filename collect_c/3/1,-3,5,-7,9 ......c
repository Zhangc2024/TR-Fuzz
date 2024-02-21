/*
    1,-3,5,-7,9 .....
*/
#include<stdio.h>
#include<conio.h>  
int main()
{
	int n,term,cnt,sign;
	printf("Enter no. of terms");
	scanf("%d",&n);
	term=cnt=sign=1;
	while(cnt<=n)
	{
		printf("%d,",term*sign);
		sign=-sign;
		term+=2;
		cnt++;
	}
	printf("\b ");	
	getch();
	return 0;
}
