/* c-examples by A.Shtanyuk */
/* diagramm.c - A simple char frequency diagramm (vertical) */

#include <stdio.h>
#include <string.h>

#define N 65536
#define WIDTH  80
#define HEIGHT 15

void chomp(char *str)
{
	if(str[strlen(str)-1]=='\n')
		str[strlen(str)-1]=0;
}

int main()
{
	int count[N]={0};
	unsigned char str[N];
	char diagram[HEIGHT][WIDTH];
	int i=0,j=0;

	// init diagram
	for(i=0;i<HEIGHT;i++)
		for(j=0;j<WIDTH;j++)
			diagram[i][j]=' ';

    puts("Hello, enter a string:");
	fgets(str,N,stdin);
	chomp(str);

    i=0;
	while(str[i])
	{
		count[str[i]]++;
		i++;
	}

	for(i=0,j=0;i<N;i++)
		if(count[i]>0)
		{
			int k=HEIGHT-1;
			diagram[k][j]=i;
			while(count[i]-- && k>0)
				diagram[--k][j]='#';
			j++;
		}

		for(i=0;i<HEIGHT;i++)
		{
			for(j=0;j<WIDTH;j++)
				putchar(diagram[i][j]);
			putchar('\n');
		}
			
	putchar('\n');
	return 0;
}
