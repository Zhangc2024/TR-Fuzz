//Program to accept a number and print Fibonacci sequence.

#include<stdio.h>
#include<conio.h>
void main()
{
int pre=1, cur=1, temp, i, n;
//pre means previous number
//cur means current number
clrscr();
printf("Enter number : ");
scanf("%d", &n);
printf("%d\t%d", pre, cur);

for(i=3; i<=n; i++)
{
    temp = cur;
    cur = pre + cur;
    pre = temp;
    printf("\t%d", cur);
}
getch();
}
