#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
void game (void);
main(){
	srand(time(NULL));
	game();
}
void game (void){
	int guess;
	int random;
	int scalling=101;
	int shifting=0;
	printf("************GUESS THE NUMBER GAME***********\n\n\n");
	random=shifting+rand()%scalling;

	printf("Enter your guess:");
	scanf("%d",&guess);
	printf("***Rondom number is %d***\n",random);
	if(guess==random)
		printf("\nYou win...\n");
	else {
		while(guess != random){

			 if(guess>random){
			 	scalling-=2;
				random=shifting+rand()%scalling;
					
					printf("Enter your guess:");
					scanf("%d",&guess);
					printf("\n***Rondom number is %d***\n",random);
				
			}
			if(guess<random){
				shifting+=2;
				random=shifting+rand()%(scalling-shifting);
				printf("Enter your guess:");
				scanf("%d",&guess);
				printf("\n***Rondom number is %d***\n",random);
			}	
		}
		printf("\nGuess number is %d....Selected number is %d\n",guess,random);
		printf("\nYou win...\n");

	}	
	
	
}
