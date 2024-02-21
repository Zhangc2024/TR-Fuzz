#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8
main(){
	int i;
	int numbers[10];
	int array[10]={51,37,41,54,63,85,25,64,12,3};
	int ZeroArray[10]={0};
	int Array[SIZE]={};
	int sum=0;
	for(i=0;i<10;i++)
		numbers[i]=i;
	printf("Numbers:\n");	
	for(i=0;i<10;i++)
		printf("%d th elements contains %d\n",i,numbers[i]);
	printf("\n\n\nArray:\n");	
	for(i=0;i<10;i++)
		printf("%d th elements contains %d\n",i,array[i]);
	printf("\n\n\nZeroArray:\n");	
	for(i=0;i<10;i++)
		printf("%d th elements contains %d\n",i,ZeroArray[i]);	
	for(i=0;i<SIZE;i++){
		Array[i]=rand()%10;
		sum=sum+Array[i];
	}
	printf("\n\n\nArray:\n");	
	for(i=0;i<SIZE;i++)
		printf("%d th elements contains %d\n",i,Array[i]);	
	printf("sum of Array's elements is %d",sum);	
	
		
			
		
	return 0;
}
