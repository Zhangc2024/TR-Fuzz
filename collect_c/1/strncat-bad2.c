/*
  PLOVER: BUFF.OVER
*/

/*
	Bounds checking incorrect
*/

#include <stdio.h>
#include <string.h>

#define MAXSIZE 40

void test(char *str, char *str2){
	char buf[MAXSIZE];
	if(strlen(str) < MAXSIZE)
		strcpy(buf, str);
	else
		return;
	strncat(str, str2, MAXSIZE);
	printf("results: %s\n", buf);
}

int main(int argc, char **argv){
	char *userstr;
	char *userstr2;
	if(argc > 2){
		userstr = argv[1];
		userstr2 = argv[2];
		test(userstr,userstr2);
	}
	return 0;
}
