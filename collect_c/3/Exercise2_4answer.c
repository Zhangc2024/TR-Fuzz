# include <stdio.h>
void squeeze(char s1[], char s2[]);
main(){
    char c1[] = "Hello, world!\n";
    char c2[] = "wow";
    squeeze(c1, c2);
    printf("%s\n", c1);
}

/* squeeze: delete each char in s1 which is in s2 */
void squeeze(char s1[], char s2[]){
    int i, j, k;
    for(i = k = 0; s1[i] != '\0'; i++){
        for(j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
            ;
        if(s2[j] == '\0')
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}
