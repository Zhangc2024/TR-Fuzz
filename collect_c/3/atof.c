#include <stdio.h>

#define MAXLEN 64

double atof(char s[]);
double power(double x, int y);

int main(int argc, char const *argv[])
{
	char s[MAXLEN];
	int i, c;
	while((c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}

	printf("%.10f\n", atof(s));

	return 0;
}

/* atof: convert a character string s to double */
double atof(char s[]) {
	double val, pow;
	int i, sign, exp, expsign;

	// skip spaces
	for (i = 0; s[i] == ' ' || s[i] == '\t' || s[i] == '\n'; ++i)
		;

	sign = 1;
	if (s[i] == '-') {
		sign = -1;
		++i;
	}

	for (val = 0.0; s[i] >= '0' && s[i] <= '9'; ++i) {
		val = val * 10.0 + (s[i] - '0');
	}

	if (s[i] == '.') {
		++i;
	}
	
	for (pow = 1.0; s[i] >= '0' && s[i] <= '9'; ++i) {
		val = val * 10.0 + (s[i] - '0');
		pow *= 10.0;
	}

	if (s[i] == 'e' || s[i] == 'E') {
		++i;
	}

	expsign = 1;
	if (s[i] == '-') {
		expsign = -1;
		++i;
	}

	for (exp = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
		exp = exp * 10.0 + (s[i] - '0');
	}

	return sign * val / pow * power(10.0, expsign * exp);
}

double power(double x, int y) {
	double val;
	int i;

	if (y < 0) {
		x = 1.0 / x;
		y = -y;
	}

	for (val = 1.0; y > 0; --y) {
		val *= x;
	}

	return val;
}
