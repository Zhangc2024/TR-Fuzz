#include<stdio.h>
#include<stdlib.h>
char str[100],pat[50],rep[50],ans[100];
int i,j,m,c,k,flag=0;
void stringmatch(){
     i=j=m=c=0;
     while(str[c]!='\0'){
         if(str[m]==pat[i])
         {
             i++;m++;
             if(pat[i]=='\0'){
                 flag=1;
                 for(k=0;rep[k]!='\0';k++,j++){
                     ans[j]=rep[k];
                     i=0;
                     c=m;
             }
             }
         }else{
             ans[j]=str[c];
             j++;
             c++;
             m=c;i=0;
         }
     }ans[j]='\0';
}
int main(){
    printf("\nEnter a main string\n");
    gets(str);
    printf("%s",str);
    printf("\nenter a pattern string\n");
    // fflush(stdin);
    gets(pat);
    printf("\nenter a replace string\n");
    // fflush(stdin);
    gets(rep);
    stringmatch();
    if(flag==1){
           printf("\nThe reaultant string:%s",ans);
     } else{
            printf("\npatern string not found ");

    }
    
    return 0;
}