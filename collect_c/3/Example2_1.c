#include<stdio.h>
#define MAXLINE 1000
#define LEAP 1 /* in leap years */
#define VTAB '\012' /* ASCII vertical tab */
#define BELL '\007' /* ASCII bell character */ 
#define VTAB2 '\xa' /* ASCII vertical tab */
#define BELL2 '\x7' /* ASCII bell character */ 

main() {
	
	short int sh; //int could be omitted
	long int counter;
	float f = 2e-4;
	
	int decimal = 31;
	int octal = 037; //digit whith a leading 0 is octal, '\ooo' 
	int hexa = 0x1f; //digit whith a leading 0x is hexadecilal, '\xhh', 1...9 a...f

	char x = 48;	

	char line[MAXLINE+1];
	int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];
	
	printf("%.4f\n\n", f);
	printf("NEWLINE octal: %o\012", VTAB);
	printf("BELL octal: %o\n\007", BELL);
	printf("NEWLINE hexadecimal: %x\xa", VTAB2);
	printf("BELL hexadecimal: %x\n\x7", BELL2);
	printf("\n%d decimal\n", decimal);
	printf("%o octal\n", octal);
	printf("%x hexadesimal\n", hexa);

}
