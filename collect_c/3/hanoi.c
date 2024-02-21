/* c-examples by A.Shtanyuk */
/* hanoi.c - towers of Hanoi */

#include <stdio.h>

unsigned long long count=0;

void hanoi(int num,char a,char b,char c)
{
	if(num>0)
	{
		hanoi(num-1,a,c,b);		
		printf("%llu %c--->%c\n",++count,a,c);
		hanoi(num-1,b,a,c);
	}
}

int main()
{
  char a,b,c;
  int num;
  printf("number of rings=");
  scanf("%d",&num);

  a='A';b='B';c='C';

  hanoi(num,a,b,c);
  return 0;
}