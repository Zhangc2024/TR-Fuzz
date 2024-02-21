#include <stdio.h>

void strconcat(char s[], char t[]);

int main(void) {
    return 0;
}

/* concatenate t to the end of s */
void strconcat(char s[], char t[]) {
   int i, j;

   i = j = 0;
   while(s[i] != '\0')
       i++;

   while((s[i++] = t[j++]) != '\0');
}
