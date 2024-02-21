    #include <stdio.h>
    int main(){
        int year;
        printf("Which year is curretly running");
        scanf("%d",&year);
        if(year%400==0){
            printf("Year %d is a Leap year \n",year);   
        }
        else if(year%100==0){
            printf("Year %d is not a  Leap year \n",year);   
        }
        else if(year%4==0){
            printf("Year %d is a Leap year \n",year);   
        }
        else {
            printf("Year %d is not a Leap year \n Try another!\n",year);
        }
        return 0;
    }