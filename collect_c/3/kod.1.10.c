#include <stdio.h> 
#define MAXLINE 1000 /* dopuszczalny rozmiar wirsza danych wejściowych */

int max; /* największa znana długość */
char line[MAXLINE]; /* bieżący wiersz wejścia */
char longest[MAXLINE]; /* najdłuższy wiersz */
int getLine(void);
void copy(void);

/* wypisywanie najdłuższego weirsza danych wejściowych */ 
main() 
{
    int len; /* długość bieżącego wiersza */
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = getLine()) > 0)
        if  (len > max) {
            max = len;
            copy();
        }
    if (max > 0) /* dane zawierały co najmmniej jeden wiersz */
        printf("%s", longest);
    return 0;
}

/* getLine: pobiera wiersz do tablicy s, zwraca długość */
int getLine(void)
{
    int c, i;
    extern char line[];
    
    for (i=0; i < MAXLINE-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: kopiuje 'from' do 'to', zakłada wystarczający rozmiar */
void copy(void) 
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
