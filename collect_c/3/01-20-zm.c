#include <stdio.h>
#define TABINC 4
#define MAXLINE 1000

int getline(char s[],int maxline);
void detab(char s[], char st[], int tabinc);

char s[MAXLINE];
char st[MAXLINE];

main()
{
	int i;

	while ( (i = getline(s,MAXLINE) ) > 0)
	{
        detab(s,st,TABINC);
        printf("%s", st);
	}
}

void detab(char s[], char st[], int tabinc){
    int i, j, nb;

    j = 0;
    for (i=0; s[i]!='\0' ; ++i){
        if (s[i] == '\t'){
            nb = tabinc - (j % tabinc);
            while (nb > 0){
                st[j] = ' ';
                ++j;
                --nb;
            }
        }else{
            st[j] = s[i];
            ++j;
        }
    }
    st[j] = '\0';
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim -2){        /* line still in boundaries */
            s[j] = c;
            ++j;
        }
    if (c == '\n'){
        s[j] = c;
        ++j;
        ++i;
    }
    s[j] = '\0';
    return i;
}
