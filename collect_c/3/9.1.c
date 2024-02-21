#include <stdio.h>
void passArray(int a[],int size);
void passElement(int b);
main(){
	int numbers[10]={};
	int i;
	
	printf("Numbers:\n");
	for(i=0;i<10;i++)
		printf("%3d",numbers[i]);
	
	passArray(numbers,10);	
	
	printf("\n\nModified Numbers:\n");
	for(i=0;i<10;i++)
		printf("%3d",numbers[i]);
		
	printf("\nThe value of numbers[7] is %d\n",numbers[7]);
	passElement(numbers[7]);
	
	printf("\nThe value of numbers[7] is %d\n",numbers[7]);	
	
	
	 	
}
void passArray(int a[],int size){
	int cnt;
	for(cnt=0;cnt<10;cnt++)
		a[cnt]=cnt;
	
}
void passElement(int b){
	printf("\n\nValue in function is %d\n\n",b+=10);
}
