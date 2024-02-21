#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
int count(int n[],int size, int cou);
main(){
		srand(time(NULL));
	int numbers[SIZE]={};
	int i,operand,c;
	for(i=0;i<SIZE;i++)
		numbers[i]=rand()%10;
	printf("\nNumbers:\n");
	for(i=0;i<SIZE;i++)
		printf("%3d ",numbers[i]);
	operand=rand()%10;
	c=count(numbers,SIZE,operand);
	printf("\nOperand is %d\n",operand);
	printf("\nCount is %d",c);
	
	
	
	
	
}
int count(int n[],int size, int cou){
	int i,cnt=0;
	for(i=0;i<size;i++){
		if(cou==n[i])
			cnt++;
	}
	return cnt;
}
