#include <stdio.h>
#define SIZE 15
void bubbleSort(int *n,int size);
void swap(int *element1Ptr,int *element2Ptr);
void printArray(const int * n, int size);
double median(const int *n, int *med,int size);
main(){
	int numbers[SIZE]={37,24,27,35,33,32,28,16,34,36,30,21,29,22,23};
	printf("array is:\n");
	printArray(numbers,SIZE);
	bubbleSort(numbers,SIZE);
	printf("\nArray is ascending order:\n");
	printArray(numbers,SIZE);
	int med[SIZE/5]={};
	double mean;
	mean=median(numbers,med,SIZE);
	printf("\nMedian array is:\n");
	printArray(med,SIZE/3);
	printf("\nMean is %lf",mean);		
}
void bubbleSort(int *n,int size){
	int pass,j,hold;
	for(pass=0;pass<size-1;pass++){
		for(j=0;j<size-1;j++){
			if(*(n+j)>*(n+j+1))
				swap(n+j,n+j+1);
		}
	}
	
}
void swap(int *element1Ptr,int *element2Ptr){
	
	int hold=*element1Ptr;
	*element1Ptr=*element2Ptr;
	*element2Ptr=hold;
}
void printArray(const int * n, int size){
	
	int i;
	for(i=0;i<size;i++)
		printf("%4d ",*(n+i));
}
double median(const int *n, int *med,int size){
	int i,j=0;
	double m=0;
	for(i=1;i<size;i+=3,j++)
		*(med+j)=*(n+i);
	for(i=0;i<size/3;i++)
		m=m+*(med+i);
	return m/(size/3);		
	
	
}
