/* escape : expand newline and tab into visible sequences */
/*          while copying the string t to s               */
void escape (char s[], char t[]){
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++)
        switch (t[i]){
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
    s[j] = '\0';
}



main(){
    char t[13] = "hello\n\tworld\0";
    char s[15];

    escape(s, t);

    printf("%s\n\n",t);
    printf("%s",s);
}
