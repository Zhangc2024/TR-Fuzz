#include<stdio.h>
#define MAXLINE 1000

char reverse( char s[] );
int getline( char s[],int lim );

main(){
	int i;
	char s[MAXLINE];

	while ((i = getline(s,MAXLINE)) > 0){
        //printf("length of '%s': %d\n",s,i);
        reverse(s);
        printf ("%s", s);
	}
}

int getline(char s[],int lim){
    int i, c;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 2){
            s[i] = c;
            //printf("%d - {%c}\n",i,s[i]);
        }
    //printf("i = %d\n",i);

    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
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
