#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100

int main(int argc, char const *argv[])
{
	int i, n;
	srand((unsigned) time(NULL));

	if (argc > 1) {
		n = atoi(argv[1]);
	} else {
		n = NUM;
	}

	for (i = 0; i < n; ++i) {
		printf("%d ", rand());
	}

	return 0;
}