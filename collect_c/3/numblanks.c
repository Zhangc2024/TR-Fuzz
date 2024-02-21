#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c, bc;

	bc = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			++bc;
		}
	}
	printf("%d\n", bc);
	return 0;
}