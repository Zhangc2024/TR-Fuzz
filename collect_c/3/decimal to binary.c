#include <stdio.h>
#include <math.h>

main(){
	int array[8]={};
	int a;
	printf("Enter a:");
	scanf("%d",&a);
	int i=0;
	int b=a;
	int j=0;
	int cnt;
	while(a!=-1){
		
		while(a!=0){
		a/=2;
		j++;
		}
		for(i=0;i<8-j;i++)
			array[i]=0;
		for(i=7;i>=8-j;i--){
			array[i]=b%2;
			b/=2;
			}	
		for(cnt=0;cnt<8;cnt++)
			printf("%4d ",array[cnt]);
			
		printf("\nEnter a:");
		scanf("%d",&a);
		 i=0;
		 b=a;
		j=0;	
			
	}
		
}
