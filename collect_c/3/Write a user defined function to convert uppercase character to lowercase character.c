/*Write a user defined function to convert uppercase character to lowercase character*/
#include<stdio.h>
#include<conio.h>
char up(char);
main()
{
	char ch,ans;
	printf("Enter Character");
	scanf("%c",&ch);
	ans=up(ch);
	printf("%c",ans);
	getch();
	
}
char up(char ch1)
{
	char ch2;
	if(ch1>=65 && ch1<=90)
	{
		ch2=ch1+32;
	}
	return(ch2);
}
