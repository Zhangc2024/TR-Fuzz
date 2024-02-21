#include <stdio.h>
#include <math.h>
int numberOfDigits(int x);
int sumOfDigitsR(int x,int c);
int sumOfDigitsL(int x,int c);
int isBalancedNumber(int r, int l);
main(){
	int number;
	int nd,s1,s2,balanced;
	printf("Enter the number:");
	scanf("%d",&number);
	
	nd=numberOfDigits(number);
	s1=sumOfDigitsR(number,nd);
	s2=sumOfDigitsL(number,nd);
	balanced=isBalancedNumber(s1,s2);
	if(balanced==1)
		printf("\nThis number is balanced \n");
	else
		printf("\nThis number is not balanced \n");	
	
}
int numberOfDigits(int x){
	int i=0;
	while(x!=0){
		x/=10;
		i++;
	}
	return i;

}
int sumOfDigitsR(int x,int c){
	int i;
	int sumR=0;
	for(i=1;i<=c/2;i++){
		sumR=sumR+x%10;
		x/=10;
	}
	return sumR;
}
int sumOfDigitsL(int x,int c){
	int i,ct,y,z;
	int sumL=0;
	ct=c;
	z=0;
	y=x;
	while(ct!=0){
		z=z+pow(10,ct-1)*(y%10);
		y/=10;
		ct--;		
	}
	for(i=1;i<=c/2;i++){
		sumL=sumL+z%10;
		z/=10;
	}
	return sumL;
	
}
int isBalancedNumber(int r, int l){
	if(r==l)
		return 1;
	else 
		return 0;	
}
