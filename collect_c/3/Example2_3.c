#include<stdio.h>

main() {
	
	enum boolean { NO, YES };
	
	enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
	
	enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC }; 
	
	printf("%i\n", NO);
	printf("%i\n", MAR);
	printf("%i\n", TAB);
}
