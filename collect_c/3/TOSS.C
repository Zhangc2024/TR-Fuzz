#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
   int number;
   char guess;
   char result;

   srand(time(0));
   number=rand()%2+1;
   if(number==1)
   {
	  result='h';
   }else{
	  result='t';
   }
   printf("choose 'h' for heads and 't' for tails\n");
   scanf("%c",&guess);
  if(result==guess)
  {
	 printf("Hurray,You won the toss!\n");
  }else{
	 printf("Oops!You lost the toss\n");
  }
  return 0;

}
