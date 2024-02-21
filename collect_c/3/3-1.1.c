#include <stdio.h>
#include <math.h>

main(){
	int choice;
	double x,result;
		int choicee,choice1,choice2,choice3,choice4;
	
	printf("******************************\n");
	printf("*1. Sine**********************\n");
	printf("*2. Cosine********************\n");
	printf("*3. Tangent*******************\n");
	printf("*4. Exponential***************\n");
	printf("*5. Natural Logarithm*********\n");
	printf("*6. Based-10 Lograithm********\n");
	printf("******************************\n");
	
	printf("Enter your choice\n");
	scanf("%d",&choice);
	printf("Enter value for x:\n");
	scanf("%lf",&x);
	
	switch(choice){
		case 1:
			result=sin(M_PI/180*x);
			printf("Result is %lf\n",result);
			break;
		case 2:
			result=cos(M_PI/180*x);
			printf("Result is %lf\n",result);
			break;
		case 3:
			result=tan(M_PI/180*x);
			printf("Result is %lf\n",result);
			break;				
		case 4:
			result=exp(x);
			printf("Result is %lf\n",result);
			break;
		case 5:
			result=log(x);
			printf("Result is %lf\n",result);
			break;
		case 6:
			result=log10(x);
			printf("Result is %lf\n",result);
			break;					
				
	}
	printf("************************************************************\n");
	printf("************************************************************\n");
	printf("************************************************************\n");
	printf("************************************************************\n");
	printf("************************************************************\n");
	printf("************************************************************\n");
	printf("************************************************************\n\n\n\n");
	
	

	
	printf("******************************\n");
	printf("*1. Camera********************\n");
	printf("*2. GPS***********************\n");
	printf("******************************\n");
	
	printf("Enter your selection:\n");
	scanf("%d",&choicee);
	switch(choicee){
		case 1:
			printf("******************************\n");
			printf("*1. Front*********************\n");
			printf("*2. Bottom********************\n");
			printf("******************************\n");
			printf("Enter your selection:\n");
			scanf("%d",&choice1);
			switch(choice1){
				case 1:
					printf("******************************\n");
					printf("*1. On************************\n");
					printf("*2. Off***********************\n");
					printf("******************************\n");
					printf("Enter your selection:\n");
					scanf("%d",&choice2);
					switch (choice2){
						case 1:
							printf("Front camera is On\n");
							break;
						case 2:	
							printf("Front camera is Off\n");
							break;
						default:
							printf("Wrong choice\n try again");
							break;	
					}
					break;			
					
					
				case 2:	
					printf("******************************\n");
					printf("*1. On************************\n");
					printf("*2. Off***********************\n");
					printf("******************************\n");
					printf("Enter your selection:\n");
					scanf("%d",&choice3);
					switch (choice3){
						case 1:
							printf("Bottom camera is On\n");
							break;
						case 2:	
							printf("Bottom camera is Off\n");
							break;
						default:
							printf("Wrong choice\n try again");
							break;
								}					
				break;
				
				default:
					printf("Wrong choice\n try again");
					break;	
					}
		break;
		
		case 2:
				
			printf("********************\n");
			printf("* 1.on				\n");
			printf("* 2.off				\n");
			printf("********************\n");
						
			printf("Enter the choice1");
			scanf("%d",&choice4);
			
				switch(choice4){
					case 1:
						printf("GPS is on");
						break;
					case 2:
						printf("GPS is off");
						break;
					default:
						printf("Wrong choice\n try again");
						break;	
				}
		
		break ;
		
		default: 
			printf("Wrong choice\n try again");
			break;
			
			
			
	}
return 0;

	

			
		

	
	
	
}

