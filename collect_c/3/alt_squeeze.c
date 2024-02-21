#include<stdio.h>
#define MAX 30

void squeeze(char[], int);
void alt_squeeze(char[], char[]);
int main(){
    char s[MAX] = "evanescence";
    char s1[MAX] = "blinkenlight";
    char s2[MAX] = "light";
    printf("Word:    %s\n", s);

    squeeze(s, 'e');

    printf("squeeze: %s\n", s);
    printf("s1:          %s\n", s1);
    printf("s2:          %s\n", s2);
    alt_squeeze(s1, s2);
    printf("alt_squeeze: %s\n", s1 );

    return 0;
}

/* squeeze: removes all occurences of the character
 * c from the string s
 * */
void squeeze(char s[], int c){
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/* alt_sqeeze: deletes each character in s1 that matches any character in s2
 * */
void alt_squeeze(char s1[], char s2[]){
    int i;
    /* i iterates over the s2 */
    for(i = 0; i < s2[i] != '\0'; i++){
        /* do squeeze on s1 */
        squeeze(s1, s2[i]);
    }
}
