#include <stdio.h>
#include <math.h>
int reverse(int x);
main(){
	int number;
	int reversed;
	printf("Enter number to reverse:\n");
	scanf("%d",&number);
	reversed=reverse(number);
	
	printf("reversed number is %d\n",reversed);
}
int reverse(int x){
	int y,i,z;
	y=x;
	i=0;
	z=0;
	while(x!=0){
		x=x/10;
		i++;
	}

	while(i!=0){
		z=(y%10)*pow(10,i-1)+z;
		y=y/10;
		i--;
	}
	return z;
}
