#include <stdio.h>

#define STACK_SIZE	100
#define PAIRS_NUM	7

enum pairs { NONE = 0, LCB, RCB, LP, RP, LSB, RSB, LC, RC, LMC, RMC, Q, DQ };
enum escape { ESCAPED, NOTESCAPED };

enum pairs mapchar(char c, char pc);

/* check for balance braces, paranthesis, quotes
   and comments */
int main(int argc, char const *argv[])
{
	enum pairs open_pair[PAIRS_NUM]		= {LCB, LP, LSB, Q, DQ, LC, LMC};
	enum pairs close_pair[PAIRS_NUM] 	= {RCB, RP, RSB, Q, DQ, RC, RMC};
	char stack[STACK_SIZE];
	enum pairs p, op, top;
	int i, c, pc, j;
	int nline;
	enum escape e = NOTESCAPED;

	i = 0;
	pc = 0;
	nline = 1;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			++nline;
		}

		top = NONE;
		if (i > 0) {
			top = stack[i-1];
		}

		p = mapchar(c, pc);
		if (p != NONE) {
			// a pair symbol found

			// check for escaped quote
			if (p == Q && e == ESCAPED && (top == Q || top == DQ)) {
				// escaped quote inside a character string
				p = NONE;
			}

			for (j = 0; j < PAIRS_NUM && close_pair[j] != p; ++j) {
			}

			if (j < PAIRS_NUM) {
				// probably a closing pair symbol
				op = open_pair[j];

				if (top == op) {
					// match, pop off the stack
					--i;
				} else {
					// mismatch
					if (p == Q || p == DQ) {
						// a possible quote starts
						if (top != LC && top != LMC) {
							// not inside a comment
							if (p == Q && top != DQ || p == DQ && top != Q) {
								// checking for nested quotes
								stack[i++] = p;	
							}
						}
					} else if (p == RC) {
						// new line is ok
					} else if (top != LC && top != LMC && top != Q && top != DQ) {
						printf("unbalanced symbol: %d after opening %d at line %d\n", p, top, nline);
						return 1;
					}
				}
			} else {
				// have to be an open pair symbol
				if (top != LC && top != LMC && top != Q && top != DQ) {
					// check that we're not in the comments or quoted strings, otherwise put in the stack
					stack[i++] = p;
				}
			}

			if (i >= STACK_SIZE) {
				// stack overflow
				printf("error: stack overflow\n");
				return 1;
			}
		}

		// handling escaped characters inside quoted strings
		if (c == '\\' && (top == Q || top == DQ) && e == NOTESCAPED) {
			e = ESCAPED;
		} else if ((top == Q || top == DQ) && e == ESCAPED) {
			e = NOTESCAPED;
		}

		pc = c;
	}

	if (i > 0) {
		printf("unbalanced symbol: %d\n", stack[i-1]);
		return 1;
	}

	printf("balance is ok\n");
	return 0;
}

enum pairs mapchar(char c, char pc) {
	if (c == '{') {
		return LCB;
	}
	if (c == '}') {
		return RCB;
	}
	if (c == '(') {
		return LP;
	}
	if (c == ')') {
		return RP;
	}
	if (c == '[') {
		return LSB;
	} 
	if (c == ']') {
		return RSB;
	}
	if (c == '\'') {
		return Q;
	} 
	if (c == '"') {
		return DQ;
	} 
	if (c == '/' && pc == '/') {
		return LC;
	} 
	if (c == '\n') {
		return RC;
	}
	if (c == '*' && pc == '/') {
		return LMC;
	}
	if (c == '/' && pc == '*') {
		return RMC;
	}
	return NONE;
}
