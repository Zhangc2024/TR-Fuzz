#include <stdio.h>

#define BUF_LEN 100
#define IN 		1
#define OUT 	0

/* remove comments from C code; 
   - single line and multi line comments;
   - ignore // inside multi line comments;
   - ignore "" inside comments */
int main(int argc, char const *argv[])
{
	int i, c, pc;
	char buf[BUF_LEN+1];
	int singlecomment = OUT;
	int multicomment = OUT;
	int quotedstring = OUT;

	char str[100] = "should ignore // inside quoted strings";

	i = 0;
	buf[BUF_LEN] = '\0';

	while ((c = getchar()) != EOF) {
		if (c == '"' && !quotedstring && !singlecomment && !multicomment) {
			quotedstring = IN;
		} else if (c == '"') {
			quotedstring = OUT;
		}

		if (quotedstring == OUT) {
			if (c == '/' && pc == '/' && !multicomment) {
				// comment started
				singlecomment = IN;
				--i;
			} else if (c == '\n' && singlecomment == IN) {
				// comment ended
				singlecomment = OUT;
			} else if (c == '*' && pc == '/') {
				// multi line comment started
				multicomment = IN;
				--i;
			} else if (c == '/' && pc == '*' && multicomment == IN) {
				multicomment = OUT;
				continue;
			}
		}

		if (i >= BUF_LEN) { // flush the buf
			printf("%s", buf);
			i = 0;
		}

		if (singlecomment == OUT && multicomment == OUT) {
			buf[i] = c;
			++i;
		}
		pc = c;
	}

	// flush the buf
	buf[i] = '\0';
	if (i > 0) {
		printf("%s\n", buf);	
	}

	return 0;
}