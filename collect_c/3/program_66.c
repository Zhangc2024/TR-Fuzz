// print decimal value of the octal number and vice-versa

#include <stdio.h>
#include <math.h>

int octalToDecimal (int octal)
{
	int decimal = 0, i = 0;

	while(octal != 0)
	{
		decimal += pow(8, i++) * (octal % 10);
		octal /= 10;
	}
	return decimal;
}

int decimalToOctal (int decimal)
{
	int octal = 0, i = 0;

	while (decimal != 0)
	{
		octal += pow(10, i++) * (decimal % 8);
		decimal /= 8;
	}
	return octal;
}

int main()
{
	int octal;

	printf("Please enter an octal number: ");
	scanf("%d", &octal);

	printf("decimal value of %d is %d and back in octal is %d.\n", octal, octalToDecimal(octal), decimalToOctal(octalToDecimal(octal)));

	return 0;
}
