/*include the libraries*/
#include <stdio.h>
#include <math.h>

/*this function converts octal numbers to binary numbers*/
long octalToBinray(int octalnum)
{
    int     decimalnum = 0, i = 0;
    long    binarynum = 0;

    /*this loop converts octal number "Octalnum" 
     *to the decimalnumber "decimalnum"
     */
    while(octalnum != 0)
    {
        decimalnum = decimalnum + (octalnum % 10) * pow(8, i);
        ++i;
        octalnum = octalnum / 10;
    }

    /*i is re-initialized*/
    i = 1;

    /*this loop converts the decimal number "decimalnum"
     *to the number "binarynum"
     */
    while(decimalnum != 0)
    {
        binarynum = binarynum + (decimalnum % 2) * i;
        decimalnum = decimalnum / 2;
        i = i * 10;
    }
    /*returning the binary number that we got from octal number*/
    return binarynum;
}

/*main part of the program*/
int main()
{
    int octalnum;

    printf("Enter the octal number: ");
    scanf("%d", &octalnum);

    /*calling the function octalToBinary*/
    printf("The binary number is: %ld\n", octalToBinray(octalnum));
    
    return 0;
}