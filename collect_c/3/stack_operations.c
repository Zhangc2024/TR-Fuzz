#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int s[MAX];
int top=-1;

void push(int item){
    if(top==MAX-1){
        printf("\nStack overflow");
    }else{
        top++;
        s[top]=item;

    }
}
void pop(){
    int item;
    if(top==-1){
        printf("\nStack underflow\n");

    }else{
        item=s[top];
        printf("Deleted element is :%d",item);
        top--;
    }
}
void display(){
    if(top==-1){
        printf("\nStack is empty");
    }else{
        printf("\nStack contents are:\n");
        for(int i=top;i>=0;i--){
            printf("|%d|\n",s[i]);
        }
    }
}
void palindrome(){
    int flag=0;
     printf("\nStack contents are:\n");
        for(int i=top;i>=0;i--){
            printf("|%d|\n",s[i]);
        }
      printf("\nReverse Stack contents are:\n");
        for(int i=0;i<=top;i++){
            printf("|%d|\n",s[i]);
        }
        for(int i=0;i<=top/2;i++){
            if(s[i]!=s[top-i]){
               flag=1;
               break;
            }
        }
        if(flag==0){
            printf("\nstack contents are a palinfrome no.s");
        }else{
            printf("\nNOt a palindrome");
        }
}
int main(){
    int choice,item;
    while(1){
    printf("\n\n~~~MENU~~~\n\n");
    printf("\n1=>Push and overflow demo");
    printf("\n2=>Pop and underflow demo");
    printf("\n3=>palindrome demo");
    printf("\n4=>display");
    printf("\n5=>Exit");
    printf("\nenter your choice");
    scanf("%d",&choice);
    switch(choice){
        case 1:printf("\nEnter the element to be inserted");
               scanf("%d",&item);
               push(item);
               break;
        case 2:pop();
                break;
        case 3:palindrome();
               break;
        case 4:display();
                break;
        case 5:exit(0);
                break;
        default:printf("\nenter the valid choice");
    }
    }
    return 0;
}