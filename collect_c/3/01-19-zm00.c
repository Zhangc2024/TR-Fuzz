#include<stdio.h>
#define MAXLINE 1000

char reverse( char s[] );
int getline( char s[] );

main(){
	int i;
	char s[MAXLINE];

	while ((i = getline(s)) >= 0){
        //printf("length of '%s': %d\n",s,i);
        if (i > 0)
            reverse(s);
        printf ("%s", s);
	}
}

int getline(char s[]){
    int i, c, j;
    i = 0;

    while ((c = getchar()) != EOF){
        if (c == '\n'){
            s[i] = '\n';
            ++i;
            s[i] = '\0';
            j = i - 1;
            i = 0;
            return j;
        }else{
            s[i] = c;
            ++i;
        }
    }

    if (i > 0){
        s[i] = '\0';
        return i;
    }
}

char reverse(char s[]){
	int i,j;
	i = j = 0;
	char tmp;

	while (s[i] != '\0')
		++i;
    --i;
	if (s[i] == '\n')
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
