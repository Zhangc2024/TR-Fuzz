#include<stdio.h>

#define MAXCOL 10
#define TABINC 8

char line[MAXCOL];

int exptab(int pos);
int findblank(int pos);
int newpos(int pos);
void printline(int pos);

int main(){
    int c, pos;

    pos = 0;
    while((c = getchar()) != EOF){
        if (c == '\t')
            pos = exptab(pos);
        else if (c =='\n'){
            printline(pos);
            pos = 0;
        } else if (++pos >= MAXCOL){
            pos = findblank(pos);
            printline(pos);
            pos = newpos(pos);
        }
    }
}

void printline(int pos){
    int i;
    for(i = 0; i < pos; ++i)
        putchar(line[i]);
    if (pos > 0)
        putchar('\n');
}

int exptab(int pos){
    line[pos] = ' ';
    for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
        line[pos] = ' ';
    if (pos < MAXCOL)
        return pos;
    else{
        printline(pos);
        return 0;
    }
}

int findblank(int pos){
    while (pos > 0 && line[pos] != ' ')
        --pos;
    if (pos == 0)
        return MAXCOL;
    else
        return pos + 1;
}

int newpos(int pos){
    int i, j;
    if (pos <= 0 || pos == MAXCOL)
        return 0;
    else{
        i = 0;
        for (j = pos; j < MAXCOL; ++j){
            line[i] = line[j];
            ++i;
        }
        return i;
    }
}
