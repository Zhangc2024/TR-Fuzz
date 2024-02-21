#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
main(){
	int array[SIZE]={3,5,6,9,8,2,1,1,0,7};
	int i;
	printf("Array\n");
	for(i=0;i<SIZE;i++){
		printf("%5d\n",array[i]);
	}
	int number;
	number=rand()%10;
	printf("random number is %d\n",number);
	int hold=-1;
	for(i=0;i<SIZE;i++){
		if(number==array[i])
			hold=0;
		else
			hold=-1;	
	}
	if(hold==0)
		printf("array contains that number");
	if(hold==-1)
		printf("array does not contain that number");	
	
}
