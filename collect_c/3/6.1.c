#include <stdio.h>
int isEvenDigits(int x);

main(){
	int number;
	int even;
	
	printf("Enter value for number:");
	scanf("%d",&number);
	
	even=isEvenDigits(number);
	
	if(even==1)
		printf("This number is even");
	else
		printf("This number is odd");
		
	return 0;		

	
}
int isEvenDigits(int x){
	if(x%2==0)
		return 1;
	else
		return 0;	
}
