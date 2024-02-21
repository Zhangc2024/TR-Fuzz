#include<stdio.h>
int main()
{
    int seat,a=0,i=0;
    printf("enter seat number :");
    scanf("%d",&seat);
    a = seat%8;
    char seatLevel[]="SLMULMUS";
    char seatCnt[]="U111222L";
    printf("The seat Type is %c%c\n",seatLevel[a],seatCnt[a]);
    return 0;
}