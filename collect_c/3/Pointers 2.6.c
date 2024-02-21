#include <stdio.h>
#define SIZE 20
void printArray(const int * n, int size);
void arithmetic(int a_1,int d,int *const n,int size);
main(){
	int array[SIZE]={};
	printf("Empty array is:\n");
	printArray(array,SIZE);
	int d;
	printf("Enter value for a1 and d:\n");
	scanf("%d%d",&array[0],&d);
	arithmetic(array[0],d,array,SIZE);
	printf("\n\nAfter funtion called\n");	
	printArray(array,SIZE);
}
void printArray(const int * n, int size){
	int i;
	for(i=0;i<size;i++)
		printf("%3d ",*(n+i));
}
void arithmetic(int a_1,int d,int *const n,int size){
	int i;
	for(i=1;i<size;i++)
		*(n+i)=a_1+d*(i-1);
}
