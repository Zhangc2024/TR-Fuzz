#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[100],pat[20],rep[20],ans[100];
int i,j,c,m,k,flag=0;

void stringmatch(){
    i=j=c=m=0;
    while(str[c]!='\0'){
        if(str[m]==pat[i]){
            i++;
            m++;
            if(pat[i]=='\0'){
                flag=1;

            for(int k=0;rep[k]!='\0';k++,j++){
                ans[j]=rep[k];
                c=m;i=0;
            }
            }
        }else{
            ans[j]=str[c];
            j++;c++;
            m=c;i=0;
        }
    }
    ans[j]='\0';
}

int main(){
    printf("\nenter the main string:\n");
    fflush(stdin);
    gets(str);
    printf("\nenter the pattern string:\n");
    fflush(stdin);
    gets(pat);
    printf("\nenter the rep string:\n");
    fflush(stdin);
    gets(rep);
    stringmatch();
    if(flag==1){
        printf("\nthe Resulatant string is :%s",ans);
    }else{
        printf("pattern is not found");
    }

    return 0;
}