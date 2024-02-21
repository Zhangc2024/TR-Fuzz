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
    int i, j, k, l, pos;

    j = 0;
    pos = 0;
    for (i=0; s[i]!='\0' ; ++i){
        if (s[i] == '\t'){
            k = i - 1;
            while (s[k]==' '){
                --j;
                --k;
            }
            s[j] = '\t';
            ++j;
            pos = pos + (tabinc - pos % tabinc);
        }else if ( (pos + 1) % tabinc == 0 && s[i] == ' '){
            printf("pos = %d\n",pos);
            s[j] = ' ';
            while (s[j] == ' '){
                printf("j = %d\n",j);
                --j;
            }
            ++j;
            s[j] = '\t';
            ++j;
            ++pos;
        }else{
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
