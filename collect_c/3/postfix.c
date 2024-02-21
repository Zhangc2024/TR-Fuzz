#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int i,top=-1;
int op1,op2,s[20],res;
char postfix[50],symb;

void push(int item){
    top=top+1;
    s[top]=item;
}
int pop(){
    int item;
    item=s[top];
    top--;
    return item;
}
int main(){
    printf("\nEnter the valid postfix Expression:\n");
    scanf("%s",postfix);
    for(int i=0;postfix[i]!='\0';i++){
        symb=postfix[i];
        if(isdigit(symb)){
            push(symb-'0');
        }else{
            op2=pop();
            op1=pop();
            switch(symb){
                case '+':push(op1+op2);break;
                case '-':push(op1-op2);break;
                case '*':push(op1*op2);break;
                case '/':push(op1/op2);break;
                case '%':push(op1%op2);break;
                case '^':
                case '$':push(pow(op1,op2));break;

            }
        }
    }
    res=pop();
    printf("Result= %d",res);
    return 0;
}