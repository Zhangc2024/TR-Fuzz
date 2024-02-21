#include <stdio.h>
#include <math.h>

int numberOfDigits(int x);
int ArmstronNumber(int x,int nd);

main(){
	
	int number;
	int nofdigits;
	int armstrong;
	
	printf("Enter the number to specify armstron number or not.\n");
	scanf("%d",&number);
	nofdigits=numberOfDigits(number);
	armstrong=ArmstronNumber(number,nofdigits);
	if(armstrong==1)
		printf("\n This number is Armstron Number.");
	else
		printf("\n This number is not Armstron Number.");	
	
	return 0;
	
}
int numberOfDigits(int x){
	int i=0;
	while(x!=0){
		i++;
		x=x/10;
	}
	return i;
}
int ArmstronNumber(int x,int nd){
	int y,z=0;
	y=x;
	while(nd!=0){
		z=pow(x%10,3)+z;
		nd--;
		x=x/10;
	}
	if(z==y)
		return 1;
	else
		return 0;	
	
}
