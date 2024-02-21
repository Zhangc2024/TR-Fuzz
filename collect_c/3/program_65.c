// convert binary number to decimal number and vice-versa

#include <stdio.h>
#include <math.h>

int countDigits (int number)
{
	int temp = number;
	int count = 0;

	while (temp != 0)
	{
		temp /= 10;
		count++;
	}
	return count;
}

int binaryToDecimal (int binary)
{
	int decimal = 0, i = 0;

	while (binary != 0)
	{
		decimal += pow(2, i++) * (binary % 10);
		binary /= 10;
	}

	return decimal;
}

int decimalToBinary (int decimal)
{
	int binary = 0, i = 0;

	while (decimal != 0)
	{
		binary += pow(10, i++) * (decimal % 2);
		decimal /= 2;
	}
	return binary;
}

int main()
{
	int binary;

	printf("Please enter a binary number: ");
	scanf("%d", &binary);

	printf("%d in decimal form is %d and back to binary is %d.\n", binary, binaryToDecimal(binary), decimalToBinary(binaryToDecimal(binary)));

	return 0;
}
