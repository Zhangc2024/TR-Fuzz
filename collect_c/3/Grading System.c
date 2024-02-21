#include<stdio.h>
int main()
{
	float p;
	printf("Enter percentage obtained :");
	scanf("%f",&p);
	if(p>=90)
	printf("Grade AA");
	else if(p>=80)
	printf("Grade A+");
	else if(p>=70)
	printf("Grade A");
	else if(p>=60)
	printf("Grade B+");
	else if(p>=50)
	printf("Grade B");
	else if(p>=40)
	printf("Grade C");
	else if(p>=35)
	printf("Grade D");
	else
	printf("Fail");
	return 0;
}
