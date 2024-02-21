#include <stdio.h>
#define SIZE 100

main(){
	int c;
	char sentence[SIZE];
	int i=0,j=0;
	
	while(i<SIZE-1 && (c=getchar()) != '\n'){
		sentence[i]=c;
		printf("%d or %c is read\n",c,sentence[i]);
		i++;
	}
	sentence[i]='\0';
	printf("\n");
	for(j=0;j<i;j++)
		printf(" or %d is printed\n",putchar(sentence[j]));
	printf("\n\n\n");	
	char s[SIZE];
	int x=3;
	double y=17.5;
	sprintf(s,"we have %d numbers and their average is %3.1lf",x,y);
	printf("%s",s);
	printf("\n\n\n");	
	char v[SIZE]="3 17.5";
	int m;
	double n;
	sscanf(v,"%d%lf",&m,&n);
	printf("The value stored in v are %d and %lf",m,n);
}
