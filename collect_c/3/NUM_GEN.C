#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
   int number,guess,nguesses=1;
   clrscr();
   srand(time(0));
   number=rand()%100+1;
  //printf("the number is %d\n",number);
	printf("guess the number between 1 to 100\n");
	do{
	scanf("%d",&guess);
	if(guess>number)
	{
	   printf("lower number please!\n");
	}
	else if(guess<number)
	{
	   printf("higher number please!\n");
	}
	else
	{
	   printf("you guessed it in %d attemppts\n",nguesses);
	}
	nguesses++;
	}while(guess!=number);
	getch();
}