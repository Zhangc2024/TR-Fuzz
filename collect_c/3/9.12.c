#include <stdio.h>
#define SIZE 10
void printArray(const int array[],int size);
void reversed(int array[],int size);
main(){
	int numbers[SIZE]={3,7,10,5,4,1,6,9,2,8};
	printf("Original Arrany is:\n");
	printArray(numbers,SIZE);
	printf("\n\n");
	printf("Reversed Arrany is:\n");
	reversed(numbers,SIZE);
	printArray(numbers,SIZE);
	
}
void printArray(const int array[],int size){
	int i;
	for(i=0;i<size;i++)
		printf("%3d",array[i]);	
}
void reversed(int array[],int size){
	int i,temp;
	int end=size-1;
	for(i=0;i<size/2;i++){
		temp=array[i];
		array[i]=array[end];
		array[end]=temp;	
		end--;
	}
	
}
