#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef union
{
	struct
	{
		unsigned int mantissa: 23;
		unsigned int exponent: 8;
		unsigned int sign: 1;
	} field;
	float number;
} SinglePrecision;

#define BITLENGTH sizeof(unsigned long) * 8

char *decimal_to_binary(unsigned long decimal)
{
	int		b[BITLENGTH], remainder;
	char	*output = (char*) malloc(BITLENGTH);
	memset(output, 0, BITLENGTH); /*just to be sure it works*/
	
	int i = 0;
	do {
			remainder = decimal % 2;
			decimal = decimal / 2;
			b[i] = remainder;
			i++;
	} while (decimal >= 1);
	
	/*Remember i from before?!*/
	while (i > 0)
	{
		i--;
		strcat(output, b[i] ? "1" : "0");
	}
	
	return output;
}

/*Main code for the program*/
int main(int argc, char const *argv[])
{
	SinglePrecision a;
	a.number = -0.15625;
	printf("%s %s %s\n",
			decimal_to_binary(a.field.sign),
			decimal_to_binary(a.field.exponent),
			decimal_to_binary(a.field.mantissa));
	return 0;
}
