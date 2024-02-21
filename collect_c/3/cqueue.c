#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct{
    int front,rear;
    char arr[MAX];
}cqueue;
 
 void enqueue(cqueue *q,char item){
     if((q->rear+1)%MAX==q->front){
         printf("\nQueue is full");

    }else{  
        q->rear=(q->rear+1)%MAX;
        q->arr[q->rear]=item;
    }
    
 }
 void dequeue(cqueue *q){
     char val;
     if(q->rear==q->front){
         printf("\nQueue is empty");

     }else{
         q->front=(q->front+1)%MAX;
         val=q->arr[q->front];
         printf("Deleted element is :%c",val);

     }
     
 }
 void display(cqueue *q){
     if(q->rear==q->front){
         printf("\nQueue is empty");

     }else{
         printf("queue contents are:\n");
         for(int i=q->front+1;i<=q->rear;i++){
             printf("%c\t",q->arr[i]);
         }
     }
 }

int main(){
    cqueue q;
    q.front=q.rear=0;
    int choice;
    char c;
    while(1){
    printf("\nPress\n1=>INsertion\n2=>deletion\n3=>display\n4=>exit\n");
    printf("enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:printf("enter the character to be inserted\n");
               fflush(stdin);
               scanf("%c",&c);
               enqueue(&q,c);
               break;
        case 2:dequeue(&q);
               break;

        case 3:display(&q);
                break;
        case 4:exit(0);
        case 5:printf("enter the valid choice\n");
    }
    
    }
    return 0;
}