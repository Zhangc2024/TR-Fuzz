# include <stdio.h>
/* strlen: return length of s */
int myStrlen(const char s[]);                         /* make sure the function doesn't change s[]*/
int main() {
    char str[] = "Hello, world !";
    int length = myStrlen(str);
    printf("The length of '%s' is %d\n", str, length);
}

int myStrlen(const char s[]){
    int i;
    i = 0;
    while (s[i] != '\0')
        ++i;
    //s[0] = 'Q'; // This will invoke an error, since const is used.
    return i;
}
