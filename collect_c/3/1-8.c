#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int c;
	long nb, nt, nl;
	nb = 0;
	nt = 0;
	nl = 0;

	while((c = getchar()) != EOF){
		if(c == ' ')
			++nb;
		else if(c == '\t')
			++nt;
		else if(c == '\n')
			++nl;
	}

	printf("The number of blank is %ld\n", nb);
	printf("The number of tab is %ld\n", nt);
	printf("The number of newline is %ld\n", nl);
}
