#include<stdio.h>

#define IN 1
#define OUT 0

main(){
	int c, st, l, u;
	int i, j;
	int pal[16];
	
	l = 0;
	st = OUT;
	
	for (i = 0; i < 16; i++)
		pal[i] = 0;
		
	while((c = getchar()) != EOF){
		if (c != '\n' && c != '\t' && c != ' '){
			++l;
			st = IN;
		}
		else{
			if (st == IN){
				++pal[l];
				l = 0;
			}
			st = OUT;
		}
		u = c;
	}
	if (u != '\n' && u != '\t' && u != ' ')
		++pal[l];
	
	printf("\nLength\tAmount\tHistogram\n");
	for(i = 1; i < 16; i++){
		printf("%d\t%d\t", i, pal[i]);
		while (pal[i] != 0){
			printf("#");
			pal[i]--;
		}
		printf ("\n");
	}	
		
}
