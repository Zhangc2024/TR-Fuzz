#include <stdio.h>
#define TABINC 4
#define MAXLINE 1000

int getline(char s[],int maxline);
void entab(char s[],int tabinc);

char s[MAXLINE];
char st[MAXLINE];

main()
{
	int i;

	while ( (i = getline(s,MAXLINE) ) > 0)
	{
        entab(s,TABINC);
        printf("%s", s);
	}
}

void entab(char s[], int tabinc){
    int i, j, nt, nb, pos;

    j = 0;
    pos = 0;
    nb = 0;
    nt = 0;
    for (i=0; s[i]!='\0' ; ++i){
        if (s[i] == ' '){
             if ((pos + 1) % tabinc == 0){
                nb = 0;
                ++nt;
             }else{
                ++nb;
             }
             ++pos;
        } else if (s[i] == '\t'){
                nb = 0;
                s[j] = '\t';
                ++j;
                pos = pos + (tabinc - pos % tabinc);
        } else {
            //printf("%d - %d\n",nb, nt);
            while (nt > 0){
                s[j]='\t';
                --nt;
                ++j;
            }
            while (nb > 0){
                s[j]=' ';
                --nb;
                ++j;
            }
            s[j] = s[i];
            ++j;
            ++pos;
        }
    }
    s[j] = '\0';
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
