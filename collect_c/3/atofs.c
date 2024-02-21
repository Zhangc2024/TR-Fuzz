#include <stdio.h>
#include <ctype.h>

/* atofs: convert string s to double. It handles scientific notation of the form
 * 123.45e-6 where a floating point number may be followed by e or E and an optionally
 * signed exponent.
 *
 */

#define MAXLINE 100

double atofs(char s[]);
int _getline(char line[], int max);

/* rudimentary calculator */
int main()
{
    double sum;
    char line[MAXLINE];

    while (_getline(line, MAXLINE) > 0)
    {
        printf("\t%g\n", atofs(line)); 
    }

    return 0; //return SUCCESS
}

double atofs(char s[])
{
    double val, power;
    int i, sign, exp_sign, exp, exp_power;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.')
    {
        i++;
    }
    
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0; 
    }

    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
    }

    exp_sign = (s[i] == '-' ? -1 : 1);
    
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }

    for (exp_power = 0; isdigit(s[i]); i++)
    {
        exp_power = 10 * exp_power + (s[i] - '0');
    }
    
    exp = 1;
    
    while (exp_power > 0)
    {
        exp = 10 * exp;
        exp_power--;
    }

    if (exp_sign > 0) {

        return  (sign * val / power) * exp;
    }
    else {
        
        return (sign * val / exp) * (1 / power); 
    }
}

int _getline(char line[], int max)
{
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        i++;
    }

    line[i] = '\0';
    
    return i;
}

