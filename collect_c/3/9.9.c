#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int minimum(int a[],int size);
main(){
	srand(time(NULL));
	int numbers[SIZE]={};
	int i,min;
	for(i=0;i<SIZE;i++)
		numbers[i]=rand()%10;
	printf("\nNumbers:\n");
	for(i=0;i<SIZE;i++)
		printf("%8d\n",numbers[i]);
	min=minimum(numbers,SIZE);		
	printf("\n\nMinimum of the numbers is %d",min);
	
}
int minimum(int a[],int size){
	int hold;
	hold=a[0];
	int i;
	for(i=1;i<size;i++){
		if(a[i]<hold)
			hold=a[i];
	}
	return hold;
	
}
