/*PLOVER: BUFF.OVER, BUFF.FORMAT*/

/*
Description: Syslog is called with a user supplied format string.  An attempt was made to preformat the buffer but the vulnerability remains.
Keywords: Size0 Complex1 Taint FormatString
ValidArg: "'NormalString\n'"
InvalidArg: "%s"*100
*/

#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv)
{
	char buffer [15] = "Hello World";
        int int1=1, int2=2;
        return 1;

}

