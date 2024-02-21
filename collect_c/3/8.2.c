#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Response_SIZE 40
#define Frequency_SIZE 11
#define SIZE 10

main(){
	printf("***************************\n");
	printf("***************************\n");			
	printf("***************************\n");
	printf("***************************\n");
	printf("      1. SORU	      ");
	printf("\n\n\n");
	int answer,rating,i;
	int j;
	int frequency[Frequency_SIZE]={};
	int response[Response_SIZE]={};
	
	for(i=0;i<Response_SIZE;i++)
		response[i]=1+rand()%10;
	printf("Responses:\n");
	for(i=0;i<Response_SIZE;i++){
		printf("%2d ",response[i]);
		if(i%10==9)
			printf("\n");
	}	
	for(answer=0;answer<Response_SIZE;answer++)
		frequency[response[answer]] ++;	
	printf("Rating \t Frequency \t Histogram\n");
	for(rating=1;rating<Frequency_SIZE;rating++){
		printf("%6d \t %9d \t ",rating,frequency[rating]);
		for(j=0;j<frequency[rating];j++)
			printf("*");
		printf("\n");	
	}
	
		
		
		
	printf("\n\n\n\n\n\n");
	printf("***************************\n");
	printf("***************************\n");			
	printf("***************************\n");
	printf("***************************\n");
	printf("       2. SORU	      ");
	printf("\n\n\n");
	
	int numbers[SIZE]={19,3,5,7,11,9,13,5,17,1};

	printf("Element \t Value \t Histogram\n");
	for(i=0;i<SIZE;i++){
		printf("%7d \t %5d \t ",i,numbers[i]);
		for(j=0;j<numbers[i];j++)
			printf("*");
		printf("\n");	
		
	}
}
