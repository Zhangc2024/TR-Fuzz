#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
void printArray(const int * n, int size);
void reverse(const int *n ,int *r, int size);
int difference(const int *n , const int *r, int *d, int size);
main(){
	int numbers[SIZE]={};
	int i;
	for(i=0;i<SIZE;i++)
		*(numbers+i)=7+rand()%18;
	printf("Original Array is:\n");	
	printArray(numbers,SIZE);
	int reversed[SIZE]={};
	int diff[SIZE]={};	
	reverse(numbers,reversed,SIZE);
	printf("\nReversed Array is:\n");	
	printArray(reversed,SIZE);
	int dif;
	dif=difference(numbers,reversed,diff,SIZE);
	printf("\nDifference Array is:\n");	
	printArray(diff,SIZE);	
	printf("\nNumber of negative elements in difference array is %d",dif);
	
}
void printArray(const int * n, int size){
	int i;
	for(i=0;i<size;i++)
		printf("%4d ",*(n+i));
}
void reverse(const int *n ,int *r, int size){
	int i;
	for(i=0;i<size;i++)
		*(r+i)=*(n+size-1-i);

}
int difference(const int *n , const int *r, int *d, int size){
	int i,cnt=0;
	for(i=0;i<size;i++)
		*(d+i)=*(n+i)-*(r+i);
	for(i=0;i<size;i++){
		if(*(d+i)<0)
			cnt++;
	}	
	return cnt;
}
