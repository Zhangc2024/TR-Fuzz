#include<stdio.h>
int main(){
    enum day{sun=1,mon,tues,wed,thur,fri,sat};      //in this case we are setting the index values.
    enum day d=wed;
    enum day e=sat;
    printf("day:%d\n",d);
    printf("day:%d\n",e);
    return 0;
}

// while running the program select whichever part you want execute and rum the program.

#include<stdio.h>
int main(){
    enum day{sun,mon,tues,wed,thur,fri,sat};          //if we dont set the index values,It will automatically starts index from 0;
    enum day d=wed;
    enum day e=sat;
    printf("day:%d\n",d);
    printf("day:%d\n",e);
    return 0;
}