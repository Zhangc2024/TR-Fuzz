/*include the libraries*/
#include <stdio.h>
#include <math.h>

/*convert binary to octal*/
int binaryToOctal(long binarynum)
{
    int octalnum = 0, decimalnum = 0, i = 0;

    while(binarynum != 0)
    {
        decimalnum = decimalnum + (binarynum % 10) * pow(2,1);
        i++;
        binarynum = binarynum / 10;
    }

    i = 1;

    while(decimalnum != 0)
    {
        octalnum = octalnum + (decimalnum % 8) * i;
        decimalnum = decimalnum / 8;
        i = i * 10;
    }

    return octalnum;
}

/*main part of the program*/
int main()
{
    long binarynum;

    /*give program binary input*/
    printf("Enter a binary number: ");
    scanf("%ld", &binarynum);

    /*print the equivalent octal value*/
    printf("Equivalent octal value is: %d", binaryToOctal(binarynum));

    return 0;
}