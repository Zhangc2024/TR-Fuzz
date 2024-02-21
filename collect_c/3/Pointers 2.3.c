#include <stdio.h>
#define SIZE 10
void printArray(int *n,int size);
void reversed(int *const n ,int size);
void swap(int *element1Ptr,int *element2Ptr);
main(){
	int numbers[SIZE]={3,7,10,5,4,1,6,9,2,8};
	printf("orginal array is:\n");
	printArray(numbers,SIZE);
	reversed(numbers,SIZE);
	printf("\nReversed array is:\n");
	printArray(numbers,SIZE);	
	
}
void printArray(int *n,int size){
	int i;
	for(i=0;i<size;i++)
		printf("numbers[%d] = %d\n",i,*(n+i));
		
}
void reversed(int *const n ,int size){
	int i,temp;
	int end=size-1;
	for(i=0;i<size/2;i++){
		swap(&n[i],&n[end]);
		end--;
	}
	
	
}
void swap(int *element1Ptr,int *element2Ptr){
	int temp=*element1Ptr;
	*element1Ptr=*element2Ptr;
	*element2Ptr=temp;
}


