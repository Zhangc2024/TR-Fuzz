#include <stdio.h>
#include <string.h> // To use function strlen
#define BASE 16
#define MAX 100
#define abs(x) ((x < 0)? -(x) : (x))
/* In 2 complement number representation, take an example of word size
   as 4: 0001 (decimal 1). The smallest negative number will be 1000(-8),
   while largest positive number is 0111(7). We can see information will
   be lost if we keep n = -n the positive one as in atoi. Therefore, we
   should keep the original negative number.
   About quotient and remainder. Cited from Algorithms 4th by Sedgewick P52
   The quotient a/b rounds towards 0; the remainder a % b is defined such
   that (a / b) * b + a % b is always equal to a. For example, -14/3 and 
   14/-3 are both -4, but -14 % 3 is -2 and 14 % -3 is 2.
*/

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
    char str[MAX];
    int n = 31;
    itob(n, str, BASE);
    printf("Int %d to string %s\n", n, str);
    return 0;
}

void itob(int n, char s[], int b) {
    int i, sign;
    sign = n;
    i = 0;
    do{
        // generate digtis in reverse order
        int tmp = abs(n % b);
        // In fact, for octal this is not right. There should be 
        // a check for base == 8; and I defaultly consider only
        // decimal and hexadecimal in this case.
        s[i++] = (tmp <= 9) ? (tmp + '0') : (tmp - 10 + 'a'); 
        // n /= 10 will be negative towards 0, we change 
        // comparator from "> 0" to "!=0" 
    } while ((n /= b) != 0);
    if (sign < 0)
        s[i++] ='-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]){
    int c, i, j;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
