#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

main(){
	int A[SIZE]={};
	int B[SIZE]={};
	int sum=0;
	int i;
	for(i=0;i<SIZE;i++){
		A[i]=rand()%10;
		B[i]=rand()%10;	
	}
	printf("A array \t\tB Array\n");
	for(i=0;i<SIZE;i++){
	printf("%7d \t\t%7d\n",A[i],B[i]);
	}	
	printf("\n\n");
	for(i=0;i<SIZE;i++){
	sum=sum+A[i]*B[i];
	}	
	printf("Dot product of array A and array B is %d",sum);
	
	
}
