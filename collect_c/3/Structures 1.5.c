#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Grade{
	int q1;
	int q2;
	int q3;
	int mt;
	int final;
	double avg;
	char *letter;
};
main(){
	struct Grade st={};
	printf("Enter value for q1 q2 q3 mt and final exams\n");
	scanf("%d%d%d%d%d",&st.q1,&st.q2,&st.q3,&st.mt,&st.final);
	st.avg=st.q1*10/100+st.q2*10/100+st.q3*10/100+st.mt*25/100+st.final*45/100;
	if(st.avg>=85)
		st.letter="AA";
	else if(st.avg>=65 && st.avg<85)
		st.letter="BB";
	else if(st.avg>=45 && st.avg<65)
		st.letter="CC";	
	else if(st.avg>=35 && st.avg<45)
		st.letter="DD";
	else
		st.letter="FF";
	printf("Q1\tQ2\tQ3\tMT\tFINAL\tAVG\tLETTER\n");
	printf("%2d\t%2d\t%2d\t%2d\t%5d\t%3.2lf\t%s",st.q1,st.q2,st.q3,st.mt,st.final,st.avg,st.letter);
						
}
