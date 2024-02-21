 #include<stdio.h>
 struct emp{
     int no;
     char name[5];
     float sal;
 };
 
 int main(){
     struct emp e;
     printf("the size %d\n",sizeof(e));   
     printf("the size %d\n",sizeof(int));   
     printf("the size %d\n",sizeof(float));   
     printf("the size %d\n",sizeof(char));   
     printf("the size %d\n",sizeof(struct emp));   
     return 0;
 }