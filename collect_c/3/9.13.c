		#include <stdio.h>
#define SIZE 10
void printArray(const int array[],int size);
void shiftByOne(int array[],int size);


main(){
	int numbers[SIZE]={0,1,2,3,4,5,6,7,8,9};
	int shifting;
	printf("Enter shifting value:\n");
	scanf("%d",&shifting);
	int i;
	printf("Original Array:\n");
	printArray(numbers,SIZE);
	printf("\n\n");
	for(i=0;i<shifting;i++)
		shiftByOne(numbers,SIZE);
		
	printf("Shifting Array:\n");
	printArray(numbers,SIZE);

}
void printArray(const int array[],int size){
	int i;
	for(i=0;i<size;i++)
		printf("%3d",array[i]);	
}
void shiftByOne(int array[],int size){
	int temp, i;
	temp=array[size-1];
	for(i=size-1;i>0;i--)
		array[i]=array[i-1];
	array[0]=temp;	
	
}
