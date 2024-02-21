#include <stdio.h>
#define SIZE 5
main(){
	printf("**************************\n");
	printf("* Pointer Offset Example *\n");
	printf("**************************\n");
	int v[SIZE]={1,11,3,7,5};
	int i=0;
	int sum=0;
	
	while(i<SIZE){
		printf("sum is %d\n(v+i) = %p\n*(v+i) = %d\n\n",sum,(v+i),*(v+i));
		sum=sum+(*(v+i));
		i++;
	}
	printf("\n\n\n******************************\n");
	printf("* Pointer Arithmetic Example *\n");
	printf("******************************\n");	
	int *vPtr=v;
	i=0, sum=0;
	while(i<SIZE){
		printf("sum is %d\nvPtr = %p\n*vPtr = %d\n\n",sum,vPtr,*vPtr);
		sum=sum+*vPtr;
		i++;
		vPtr++;
	}
	
}
