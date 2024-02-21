/*
     1,-1,1,-1.......
*/
#include<stdio.h>
#include<conio.h>  
int main()
{
	int n,term,cnt;
	printf("Enter no. of terms");
	scanf("%d",&n);
	term=cnt=1;
	while(cnt<=n)
	{
		printf("%d,",term);
		term=-term;
		cnt++;
	}
	printf("\b ");	
	getch();
	return 0;
}  





