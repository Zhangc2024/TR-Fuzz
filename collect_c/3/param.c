/* c-examples by A.Shtanyuk */
/* param.c - function call parameters*/


#include <string.h>
#include <stdio.h>

void swap(int *x, int *y )
{
	int t=*x;
	*x=*y;
	*y=t;
}

void fun(char **s)
{
	char *str="++++++++";
	*s=str;
}

void fun2(char **s) // function with bug!
{
	char str[10];
	strcpy(str,"++++++++");
	*s=str; // don't do that!
}
int main()
{
	int value1=10,value2=20;
	char *s1,*s2;      
	swap(&value1,&value2);
	
	fun(&s1);
	fun2(&s2);
	printf("String1: %s\n",s1);
	printf("String2: %s\n",s2);
	return 0;
}