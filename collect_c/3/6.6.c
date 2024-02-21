#include <stdio.h>
#include <math.h>
int BinaryToDecimal(int x);

main(){
	int btd,number;
	
	printf("Enter binary number to convert to decimal form:");
	scanf("%d",&number);
	
	btd=BinaryToDecimal(number);
	
	printf("%d is converted as %d",number,btd);	
	
	
}
int BinaryToDecimal(int x){
	int i,y,sum;
	i=0;
	y=x;
	int j=0;
	sum=0;
	while(x!=0){
		i++;
		x=x/10;
	}
	while(i!=0){
		sum=sum+(y%10)*pow(2,j);
		i--;
		j++;
		y/=10;
	}
	return sum;
	
}
