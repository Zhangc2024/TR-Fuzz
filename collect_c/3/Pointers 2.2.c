#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
void printArray(int *n,int size);
int largest(int *n,int size);
main(){
	srand(time(NULL));
	int numbers[SIZE]={};
	int i;
	for(i=0;i<SIZE;i++)
		*(numbers+i)=rand()%10;
		
	printArray(numbers,SIZE);
	int larg;
	larg=largest(numbers,SIZE);	
	printf("\nLargest element of array is %d\n",larg);
}
void printArray(int *n,int size){
	int i;
	for(i=0;i<size;i++)
		printf("numbers[%d] = %d\n",i,*(n+i));
		
}
int largest(int *n,int size){
	int hold,i;
	hold=*n;
	for(i=0;i<size;i++){
		if(*(n+i)>hold)
			hold=*(n+i);
	}
	return hold;
}

