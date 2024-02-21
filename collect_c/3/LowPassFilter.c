#include <stdio.h>
#include <stdint.h>

typedef enum{
	
	First = 0,	
	Second = 1,
	Third = 2,
	Fourth = 3,
	Fifth = 4
	
}Device_Selection;

#define numberOfDevice 3
#define SIZE 16			

void LowPassFilter(const double  *input, double* output,int size, Device_Selection device);

int main(void)
{
	double input1[SIZE]={92,99,85,111,109,115,81,109,112,84,98,88,114,100,80,96};
	double output1[SIZE]= { 0 };
	
	double input2[SIZE]={98,88,89,80,100,120,94,90,87,113,103,96,86,116,83,80};
	double output2[SIZE]= { 0 };
	
	double input3[SIZE]={80,117,101,87,102,110,85,108,119,112,97,84,120,93,91,113};
	double output3[SIZE]= { 0 };
	
	int i;
	
	LowPassFilter(input1,output1,5,First);
	LowPassFilter(input2,output2,4,Second);
	LowPassFilter(input3,output3,3,Third);

	LowPassFilter(input1,output1,3,First);
	LowPassFilter(input2,output2,4,Second);
	LowPassFilter(input3,output3,5,Third);
	
	LowPassFilter(input1,output1,2,First);
	LowPassFilter(input2,output2,6,Second);
	LowPassFilter(input3,output3,3,Third);
	
	LowPassFilter(input1,output1,6,First);
	LowPassFilter(input2,output2,2,Second);
	LowPassFilter(input3,output3,5,Third);
	printf("%d",iGlobal[2]);

	printf("X\t\tX Filtered\tY\t\tYFiltered\tZ\t   Z Filtered\n");
	for(i=0;i<SIZE;i++)
		printf("%4.3lf\t\t%4.5lf\t%4.3lf\t\t%4.5lf\t%4.3lf\t   %4.5lf\n",input1[i],output1[i],input2[i],output2[i],input3[i],output3[i]);
	
	return 0;
}
void LowPassFilter(const double  *input, double* output,int size, Device_Selection device)
{
	static int iGlobal[numberOfDevice];
	static int hold[numberOfDevice];
	
	if(iGlobal[device] == 0)
	{
		*(output+(iGlobal[device])) = 0.25* *(input+(iGlobal[device]));
		iGlobal[device]+=1;
		hold[device] = iGlobal[device]+size;
		for(iGlobal[device];iGlobal[device]<hold[device];iGlobal[device]++)
			*(output+(iGlobal[device])) = *(output+(iGlobal[device])-1)*0.75 + 0.25* (*(input+(iGlobal[device])));
	}
	else
	{	
		hold[device] = iGlobal[device]+size;
		for(iGlobal[device];iGlobal[device]<hold[device];iGlobal[device]++)
			*(output+(iGlobal[device])) = *(output+(iGlobal[device])-1)*0.75 +0.25* *(input+(iGlobal[device]));
	}
}
