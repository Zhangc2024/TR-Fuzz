#include <stdio.h>

main()
{
	int not_eof;

	while (not_eof = (getchar() != EOF)) {
		printf("NOT EOF: %d\n", not_eof);
	}
	printf("NOT EOF: %d\n", not_eof);
}
