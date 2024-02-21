#define MAXLINE 100		/* maximum line size */
#define YES 1

/* tabpos: determine if pos is at a tab stop */
int tabpos(int pos, char *tab)
{
	if (pos > MAXLINE)
		return YES;
	else
		return tab[pos];
}
