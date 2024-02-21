#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30
void printArray(const int *n,int size);
void bubbleSort(int *n,int size);
void swap(int *element1Ptr, int *element2Ptr);
int count (const int *sortedArray,const int size, const int oprnd);
main(){
	srand(time(NULL));
	int numbers[SIZE]={};
	int temp[SIZE]={};
	int i;
	for(i=0;i<SIZE;i++)
		*(numbers+i)=rand()%10;
	for(i=0;i<SIZE;i++);
		*(temp+i)=*(numbers+i);	
	printf("Array is:\n");	
	printArray(numbers,SIZE);
	int sorted[SIZE]={};
	bubbleSort(numbers,SIZE);	
	for(i=0;i<SIZE;i++)
		*(sorted+i)=*(numbers+i);
	printf("\nSorted Array is:\n");	
	printArray(sorted,SIZE);	
	int select;
	select=rand()%10;
	printf("\nOperand is %d\n",select);	
	int c;
	c=count(sorted,SIZE,select);
	printf("\nNormal Array is:\n");	
	printArray(numbers,SIZE);
	printf("\nSorted Array is:\n");	
	printArray(sorted,SIZE);
	printf("count is %d",c);	
	
	
	
}
void printArray(const int *n,int size){
	int i;
	for(i=0;i<size;i++){
		printf("%3d",*(n+i));
		if(i%10==9)
			printf("\n");
	}
		
}
void bubbleSort(int *n,int size){
	int j,pass,hold;
	for(pass=0;pass<size-1;pass++){
		for(j=0;j<size-1;j++){
			if(*(n+j)>*(n+j+1)){
		       	swap(n+j,n+j+1);
		/*	hold=*(n+j);
			*(n+j)=*(n+j+1);
			*(n+j+1)=hold;*/
			}
		}
	}
}
void swap(int *element1Ptr, int *element2Ptr){
	int hold=*element1Ptr;
	*element1Ptr=*element2Ptr;
	*element2Ptr=hold;
	
}
int count (const int *sortedArray,const int size, const int oprnd){
	int i,cnt=0;
	for(i=0;i<size;i++){
		if(*(sortedArray+i)==oprnd)
			cnt++;
	}
	return cnt;
}
