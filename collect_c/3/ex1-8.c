#include <stdio.h>

/* count blanks, tabs, and newlines */
main()
{
	int ns, c;

	ns = 0;
	while ((c = getchar()) != EOF)
		if (c == ' ' || c == '\t' || c == '\n')
			++ns;
	printf("%d\n", ns);
}
