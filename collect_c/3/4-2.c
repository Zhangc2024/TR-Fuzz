#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

double atof1(char *s);
double atof2(char *s);
int atoi1(char *s);

double atof1(char *s) {
	double val, pow;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;

	for (val = 0.; isdigit(s[i]); i++) {
		val = val * 10. + s[i] - '0';
	}

	if (s[i] == '.')
		i++;

	for (pow = 1.; isdigit(s[i]); i++) {
		pow *= 10.;
		val = val * 10. + s[i] - '0';
	}

	return sign * (val /= pow);

}

double atof2(char *s) {
	double val, pow;
	int i, exp, sign;

	/*	Consuming all whiteblanks */
	for (i = 0; isspace(s[i]); i++)
		;

	/*	Sign of the number	 */
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		i++;

	/*	Calculate the integer part	*/
	for (val = 0.; isdigit(s[i]); i++) {
		val = val * 10. + s[i] - '0';
	}

	/*	Detect Fraction	*/
	if (s[i] == '.')
		i++;
	for (pow = 1.; isdigit(s[i]); i++) {
		pow *= 10.;
		val = val * 10. + s[i] - '0';
	}

	val = sign * val / pow;

	/*	Detect Scientific Notation	*/
	if (s[i] == 'e' || s[i] == 'E') {
		sign = (s[++i] == '-') ? -1 : 1;
		if (s[i] == '-' || s[i] == '+')
			i++;
	}

	/*	Calculate exponent	*/
	for (exp = 0; isdigit(s[i]); i++)
		exp = 10 * exp + s[i] - '0';

	if (sign == -1)
		while (exp-- > 0)
			val /= 10.;
	else
		while (exp-- > 0)
			val *= 10.;

	return val;
}

int atoi1(char *s) {
	return (int) atof2(s);
}

