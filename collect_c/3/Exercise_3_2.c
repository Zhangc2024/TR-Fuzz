# include <stdio.h>
void escape(char s[], char t[]);
int main() {
    int i = 0;
    char s1[20];
    char s2[20] = "Peng\t\nWang";
    escape(s1, s2);
    printf("s2: %s\n", s2);
    printf("s1: %s\n", s1);
    return 0;
}
/* escape(s,t) converts newline and tab into visible escape sequences
like \n and \t as it copies the string t to s*/
void escape(char s[], char t[]){
    int i, j;
    for(i = j = 0; t[i] != '\0'; i++){
        switch(t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    }
    s[j] = '\0';
}
