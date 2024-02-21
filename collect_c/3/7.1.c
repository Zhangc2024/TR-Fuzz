#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int game(void);

main(){
	srand(time(NULL));
	
	int g;
	
	g=game();
	
	if(g==1)
		printf("You Win...");
	else
		printf("You Lost");

}
int game(void){
	int i,x,y;
	x=1+rand()%6;
	y=1+rand()%6;
	printf("Rondom numbers are %d and %d sum of them is %d\n",x,y,x+y);
	if(x+y==11 || x+y==7)
		return 1;
	else if(x+y==2 || x+y==3 || x+y==12)
		return 0;
	else{
		while(x+y!=11|| x+y!=7 || x+y!=2 || x+y!=3 || x+y!=12){
				x=1+rand()%6;
				y=1+rand()%6;
				printf("Rondom numbers are %d and %d sum of them is %d\n",x,y,x+y);
				if(x+y==11 || x+y==7)
					return 1;
				else if(x+y==2 || x+y==3 || x+y==12)
					return 0;		
		}
	}		
	
}
	

