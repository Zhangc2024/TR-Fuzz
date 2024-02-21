#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int stonepapersizer(char you,char comp)//if draw then return0,if win then return 1or if loose then return -1
{
   if(you==comp)                                 //possible outcomes:
   {                                            //sp,ps,pc,cp,sc,cs
	 return 0;
   }
   if(you=='s'&&comp=='p'){
	  return -1;
   }else if(you=='p' &&comp=='s')
   {
	  return 1;
   }
   if(you=='p'&&comp=='c')
   {
	 return -1;
   }else if(you=='c'&&comp=='p')
   {
	 return 1;
   }
	if(you=='s'&&comp=='c')
   {
	 return 1;
   }else if(you=='c'&&comp=='s')
   {
	 return -1;
   }
}
int main()                                     // s-stone
{                                              // p-paper
   char you;
   char comp;                                 // c-sizer
   int number,result;
   srand(time(0));
   number=rand()%10+1;
   //printf("the number is %d",number);
   if(number<3)
   {
	  comp='s';
   }else if(number>3&&number<6)
   {
	  comp='p';
   }else{
	  comp='c';
   }
   printf("enter 's' for stone,'p' for paper,'c' for sizer\b\n");
   scanf("%c",&you);
   result=stonepapersizer(you,comp);
   if(result==0)
   {
	  printf("match draw!\n");
   }else if(result==1)
   {
	  printf("you win!\n");
   }else{
	  printf("you lose!\n");
   }
   printf("the computer chose %c and you chose %c",comp,you); 
   return 0;
}