#include <stdio.h>
#include <stdlib.h>
#define Response_SIZE 40
#define Frequency_SIZE 11
int mode(const int array[],int r_size,int fre[],int f_size);
main(){
	
	int i,mostFrequent;
	int frequency[Frequency_SIZE]={};
	int responses[Response_SIZE]={};

	for(i=0;i<Response_SIZE;i++){
		responses[i]=1+rand()%10;
	}
	printf("Responses:\n");
	for(i=0;i<Response_SIZE;i++){
		printf("%2d ",responses[i]);
		if(i%10==9)
			printf("\n");
	}
	
	mostFrequent=mode(responses,Response_SIZE,frequency,Frequency_SIZE);
	printf("\n\nMode of the array is %d",mostFrequent);
	
}
int mode(const int array[],int r_size,int fre[],int f_size){
	int rating,answer,j;
	
	for(answer=0;answer<r_size;answer++)
		fre[array[answer]]++;
	printf("Rating \t\t Frequency \t Histogram\n");
	for(rating=1;rating<f_size;rating++){
		printf("%6d \t\t %9d \t ",rating,fre[rating]);
			for(j=0;j<fre[rating];j++)
				printf("*");
			printf("\n");	
	}	
int max=fre[0],index;
for(rating=1;rating<f_size;rating++){
	if(fre[rating]>max){
		max=fre[rating];
		index=rating;
	}
}	
	return index;
	
}
