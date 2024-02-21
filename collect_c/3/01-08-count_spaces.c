#include <stdio.h>

main()
{
	int c, nt, nb, nl;
	c = 0;
	nt = 0;
	nb = 0;
	nl = 0;
	
	while ((c = getchar()) != EOF)
	{
		if  (c == '\t')
			++nt;
		if  (c == ' ')
			++nb;
		if  (c == '\n')
			++nl;
	}
	
	printf("table=%d blank=%d newline=%d", nt,nb,nl);
	getchar(); 
}