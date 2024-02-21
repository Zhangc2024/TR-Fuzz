#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
int triangular(int shifting, int scalling);

main(){
	srand(time(NULL));
	int sf,sc;
	int func;
	printf("Enter value for shifting and scalling:\n");
	scanf("%d%d",&sf,&sc);
	
	func=triangular(sf,sc);
	if(func==1)
		printf("\nThey can construct a trinagle\n");
	else
		printf("\nThey cannot construct a trinagle\n");
}
int triangular(int shifting, int scalling){
	int x,y,z;
	x=shifting+rand()%scalling;
	y=shifting+rand()%scalling;
	z=shifting+rand()%scalling;
	printf("x = %d\ny = %d\nz = %d\n",x,y,z);
	if(x+y>=z && y+z>=x && x+z>=y)
		return 1;
	else 
		return 0;	
	
}

