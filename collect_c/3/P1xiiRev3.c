#include<stdio.h>
int main()
{
	int b=1,c=1,d=1,sum,sum3,sum5,sum15,flag5,flag3,flag15;
	flag5=1000/5;
	flag3=1000/3;
	flag15=1000/15;
	flag5=flag5-1;
	flag3=flag3-1;
	flag15=flag15-1;
	while(b<=flag3)
	{
		sum3=sum3+(b*3);
		b++;
	}
	while(c<=flag5)
	{
		sum5=sum5+(c*5);
		c++;
	}
	while(d<=flag15)
	{
		sum15=sum15+(d*15);
		d++;
	}
	sum=sum3+sum5-sum15;
	printf("The Result is %d",sum);
	return 0;
}