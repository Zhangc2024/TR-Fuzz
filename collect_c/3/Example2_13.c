#include<stdio.h>

main() {

	int i, c, n;
	char a[1000];
	
	for (n = 0; (c = getchar()) != EOF && c!='\n'; ++n)
		a[n] = c;
		
	for (i = 0; i < n; i++)
		printf("%6d%c", a[i], (i%10==9 || i==n-1) ? '\n' : ' '); 
	
	printf("\nYou have %d item%s.\n", n, n==1 ? "" : "s");

}


