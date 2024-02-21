#include<stdio.h>
int main()
{
	int p,c,m,t;
	float avg;
	printf("Enter your Phys. Chem. and Math marks ");
	scanf("%d%d%d",&p,&c,&m);
	t=p+c+m;
	avg=t/3;
	printf("Marks Obtained : %d and The Avarage Marks is : %f",t,avg);
	return 0;
}
