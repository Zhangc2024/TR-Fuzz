#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*further exercises about the reverse polish calc will be build upon each other*/

#define MAXOP	100
#define	NUMBER	'0'

enum {
	
		COS,
		SIN,
		EXP,
		POW,
		SQRT,
		UNKNOWN
};

double variables[26];

void	clear_stack (void);
void	push  (double f);
double	pop	  (void);
int		getop (char s[]);

int main()
{
	int		i, type;
	double	op1, op2;
	char	s[MAXOP];
	
	for (i = 0; i < 26; i++)
		
			variables[i] = 0.0;
	
	while ((type = getop(s)) != EOF)
	
			switch (type)
			{
				case NUMBER:
				
						push(atof(s));
						break;
						
				case '<':
				case '>':
				
						if ((i = s[0] - 'a') < 0 || i > 26)
						
								printf("Error: Incorrect variable!\n");
								
						else {
							if (type == '>')
							
									variables[i] = pop();
									
							push(variables[i]);
						}
						break;
						
				case COS:
				
						push(cos(pop()));
						break;
						
				case SIN:
				
						push(sin(pop()));
						break;
						
				case EXP:
				
						push(exp(pop()));
						break;
						
				case POW:
				
						op2 = pop();
						push(pow(pop(), op2));
						break;
						
				case SQRT:
				
						push(sqrt(pop()));
						break;
	
				case '!':
				
						op1 = pop();
						op2 = pop();
						push(op1);
						push(op2);
						break;
						
				case '&':
				
						clear_stack();
						break;
						
				case '+':
				case '*':
				
						if (type == '+')
						
							push(pop() + pop());
							
						else
						
							push(pop() * pop());
							
						break;
						
				case '-':
				
						op2 = pop();
						push(pop() - op2);
						break;
						
				case '/':
				case '%':
				
						if ((op2 = pop()) != 0.0)
						{
							if (type == '/')
							
								push(pop() / op2);
								
							else
							{
								op1 = pop();
								push(op1 - op2 * ((int) (op1 / op2)));
							}
						}
						else
							
							printf("Error: Zero divisor!\n");
							
						break;
				
				case '=':
				case '\n':
				
						printf("\t%.8g\n", pop());
						if (type == '=')
						
								push(op1);
								
						break;
						
				case UNKNOWN:
				default:
				
						printf("Error: Unknow command %s!\n", s);
						break;
						
			}
			
	return 0;
	
}

#define MAXVAL		100

int		sp = 0;
double	val[MAXVAL];

void clear_stack (void)
{
	sp = 0;
}

void push (double f)
{
	if (sp < MAXVAL)
	
			val[sp++] = f;
			
	else
	
			printf("Error: Stack is full, cannot push %g!\n", f);
}

double pop (void)
{
	if (sp > 0)
	
			return val[--sp];
			
	else
	{
		printf("Error: Stack is empty, cannot pop!\n");
		return 0.0;
	}
}

int getch(void);


int getop (char s[])
{
	static int	pushback = -1;
	int			i, c, d;
	
	if (pushback != -1)
	{
		s[0] = c = pushback;
		pushback = -1;
	}
	else
		
		s[0] = c = getch();
	
	while (c == ' ' || c == '\t')
	
		s[0] = c = getch();
			
	if (c == '<' || c == '>')
	{
		s[0] = getch();
		return c;
	}
	else if (isalpha(c))
	{
		i = 0;
		while (isalpha(s[++i] = c = getch()))
		
				;
				
		if (c != EOF)
		
			pushback = c;
				
		s[i] = '\0';
		if (!strcmp(s, "cos"))
		
				return COS;
				
		else if (!strcmp(s, "sin"))
		
				return SIN;
				
		else if (!strcmp(s, "exp"))
		
				return EXP;
				
		else if (!strcmp(s, "pow"))
		
				return POW;
				
		else if (!strcmp(s, "sqrt"))
		
				return SQRT;
				
		else
		
				return UNKNOWN;
				
	}
	else if (!isdigit(c) && c != '.')
	{
		if (c == '.')
		{
			if (isdigit(d = getch()) || d == '.')
			
					s[i = 1] = c = d;
					
			else
			{
				if (d != EOF)
				
					pushback = d;
					
				s[1] = '\0';
				return c;
			}
		}
		else
		{
			s[1] = '\0';
			return c;
		}
	}
	else
	
		i = 0;
		
	if (isdigit(c))
	
			while (isdigit(s[++i] = c = getch()))
			
					;
					
	if (c == '.')
	
			while (isdigit(s[++i] = c = getch()))
			
					;
				
	s[i] = '\0';
	if (c != EOF)
	
		pushback = c;
			
	return NUMBER;
}

int getch(void)
{
	return getchar();
}



	