#include <ctype.h>
#include <stdio.h>
#define MAXLINE 100

double atof(char s[]);
int getline(char s[], int lim);

main() {

	double sum, atof(char []);
	char line[MAXLINE];
	int getline(char line[], int max); 

	sum = 0;
	while (getline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));
	
	return 0;
}

int getline(char s[], int lim) {
	
	int c, i;
	i = 0;
	
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	
	if (c == '\n')
		s[i++] = c; 
	
	s[i] = '\0';
	
	return i;
}

double atof(char s[]) { 

	double val, power, exp, si = 1, pot;
	int i, sign;
	
	for (i = 0; isspace(s[i]); i++);
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if (s[i] == 'e'|| s[i] == 'E')
		i++;
	si = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (pot = 0; isdigit(s[i]); i++)
		pot = 10 * pot + (s[i] - '0');
	for (exp = 0; exp != pot; exp++)
		val = (si == 1) ? val*10.0 : val/10.0;

	return sign * val/ power;
}
