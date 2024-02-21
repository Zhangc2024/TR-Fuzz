#include <stdio.h>
#define SIZE 3
void printArray(int *n,int size);
void cross(int *c, const int *a, const int *b);
main(){
	int c[SIZE]={};
	int a[SIZE]={};
	int b[SIZE]={};
	printf("Enter value for array a:\n");
	int i;
	for(i=0;i<SIZE;i++)
	  scanf("%d",(a+i));
	 printf("Enter value for array b:\n"); 
	for(i=0;i<SIZE;i++)
	  scanf("%d",(b+i)); 
	printf("Array a is\n");
	printArray(a,SIZE);
	printf("\nArray b is\n");
	printArray(b,SIZE);
	cross(c,a,b);
	printf("\n\nAfter funtion called\n");
	printf("Array a is\n");
	printArray(a,SIZE);
	printf("\nArray b is\n");
	printArray(b,SIZE);
	printf("\nArray c is\n");
	printArray(c,SIZE);  
	
	
}
void printArray(int *n,int size){
	int off;
	for(off=0;off<size;off++)
		printf("%4d ",*(n+off));
}
void cross(int *c, const int *a, const int *b){
	*(c)=*(a+1)**(b+2)-*(a+2)**(b+1);
	*(c+1)=*(a+3)**(b)-*(a)**(b+2);
	*(c+2)=*(a)**(b+1)-*(a+1)**(b);
}
