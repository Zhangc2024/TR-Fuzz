#include <stdio.h>
main(){
	int i,a=3,b=5;
	int array[10]={};
	FILE  *wfptr;
	if((wfptr=fopen("dummy.dat","w"))==NULL)	
		printf("File could not be opened\n");
	else{
		fprintf(wfptr,"Hello World!\n");
		fprintf(wfptr,"%d + %d = %d\n",a,b,a+b);
		for(i=0;i<10;i++)
			fprintf(wfptr,"%3d",array[i]);
		printf("Enter a and b\n");
		
		while(!feof(stdin))	{
			fprintf(wfptr,"\n%d + %d = %d",a,b,a+b);
			scanf("%d%d",&a,&b);
		}
		fclose(wfptr);
	}
	
}
