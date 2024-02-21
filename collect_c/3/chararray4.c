#include <stdio.h>

#define MAXLINE 1000

int		getline(char line[], int limit);
void	reverse(char s[]);

int main()
{
	int  len;
	char line[MAXLINE];
	
	while ((len = getline(line, MAXLINE)) > 0)
	{
		reverse(line);
		printf("%s", line);
	}
	
	return 0;
}

int getline (char line[], int limit)
{
	int i, c;
	
	for (i = 0; i  < limit - 1 && (c = getchar()) != EOF && c != '\n';
		 i++)
		 
		 line[i] = c;
		 
	if (c == '\n')
	{
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	
	return i;
}

void reverse (char s[])
{
	int i, j, c;
	
	i = 0;
	
	for (j = 0; s[j] != '\n'; j++)
	
			;
			
		
	if (j > 1)
	
		while (i < j)
		{
			c = s[i];
			s[i] = s[j];
			s[j] = c;
			
			i++;
			j--;
		}
}
