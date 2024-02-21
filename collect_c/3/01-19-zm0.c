#include<stdio.h>
#define MAXLINE 1000

char reverse( char s[] );

main(){
	int i, c;
	char s[MAXLINE];

	i = 0;
	while ((c = getchar()) != EOF){
        if (c != '\n'){
            s[i] = c;
            ++i;
        }else{
            s[i] = c;
            ++i;
            s[i] = '\0';
            //printf ("before{%s}",s);
            reverse(s);

            printf ("%s", s);
            i=0;
        }
	}
    if (i > 0){
        ++i;
        s[i] = '\0';
        reverse(s);
        printf ("%s", s);
    }
}

char reverse(char s[]){
	int i,j;
	i = j = 0;
	char tmp;

	while (s[i] != '\0')
		++i;
    --i;
	if (s[i] = '\n')
		--i;

    if (i > 0){
        while ( j < i ){
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
                --i;
                ++j;
        }
    }
}
