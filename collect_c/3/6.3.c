#include <stdio.h>
int sumofDigits(int x);
int isHarshadNumber(int x,int s);

main(){
	int number,sum,harshad;
	
	printf("Enter number\n");
	scanf("%d",&number);
	
	sum=sumofDigits(number);
	harshad=isHarshadNumber(number,sum);
	if(harshad==1)
		printf("\n%d is Harshad Number.\n",number);
	else
		printf("\n%d is not Harshad Number.\n",number);	
	
}
int sumofDigits(int x){
	int y=0;
	while(x!=0){
		y=y+x%10;
		x=x/10;
	}
	return y;
}
int isHarshadNumber(int x,int s){
	if(x%s==0)
		return 1;
	else
		return 0;	
}
