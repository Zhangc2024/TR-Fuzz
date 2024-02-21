#include<stdio.h>
int cq[50];
int front=-1,rear=-1,size,item,next,i;
int choice;
void encqueue()
{
   printf("Enter the element:\n");
   scanf ("%d",&item);  
if(front==((rear+1)%size))
   printf("circular queue is full");
  else
   if(front==-1)
      {
       front=0;
       rear=0;
       cq[rear]=item;
      }
   else
      {
         next=(rear%size)+1;
         if(next!=front)
            {
             rear=(rear%size)+1;
              cq[rear]=item;
             }
          else
       printf(" Circular Queue overflow\n");
      }
}
void decqueue()
{
  if(front==-1)
  printf("Circular Queue underflow!!\n");
else
  {
    item=cq[front];
    printf("\n deleted element is:%d",item);
    if(front==rear)
     {
          rear=-1;
          front=-1;
     }
    else
       front=(front%size)+1;
  }
}

void display()
{  
   if(front==-1)
      printf("Circular Queue is empty");
    else
      {
        printf("The Circular Queue is \n");
        for(i=front;i<=rear;i++)
            printf("%d\n",cq[i]);
      }
}

void main()
{
printf("Enter the size of the circular queue\n");
scanf("%d",&size);
do
  {
    printf("\n ***MENU*** \n");
    printf("1.ADD AN ELEMENT \n");
    printf("2.DELETE AN ELEMENT \n");
    printf("3.DISPLAY\n");
    printf("4.EXIT\n");
    printf("ENTER YOUR CHOICE\n");
    scanf("%d",&choice);
    switch(choice)
        {
          case 1: encqueue();
          break;
          case 2: decqueue();
          break;
          case 3: display();
          break;
          case 4: printf("exiting from program\n");
          break;
          default:
          printf("invalid entry\n");
          break;
        }
   }
   while(choice!=4);
}