#include <stdio.h> 

main() {
	
	int c, asterisck;
	int parenthesis, brackets, braces, quotes, quote, coment, scs, bcb;
	parenthesis = brackets = braces = quote = quotes = coment = scs = bcb = 0;
	
	while((c = getchar()) != EOF) {
		switch (c) {
			case '(': parenthesis++; if (scs) scs--; break;
			case '[': brackets++; if (scs) scs--; break;
			case '{': braces++; if (scs) scs--; break;
			case ')': parenthesis--; if (scs) scs--; break;
			case ']': brackets--; if (scs) scs--; break;
			case '}': braces--; if (scs) scs--; break;
			case '\'': quote = !quote; if (scs) scs--; break;
			case '"': quotes = !quotes; if (scs) scs--; break;
			case '/': coment = !coment; if (scs) scs--; break;
			case '*': if (scs) scs--; if (coment) asterisck = !asterisck; break;
			case '\\': scs++; bcb++; break;
			case 't': if (scs && bcb > 0) { bcb--; scs--; }; break;
			case 'n': if (scs && bcb > 0) { bcb--; scs--; } break;
			case 'b': if (scs && bcb > 0) { bcb--; scs--; } break;
			case 'r': if (scs && bcb > 0) { bcb--; scs--; } break;
			case 'a': if (scs && bcb > 0) { bcb--; scs--; } break;
			default : if (scs) scs--; 
		}
		
	}

	printf("\n%d Parentesis Left\n", parenthesis);
	printf("%d Brackets Left\n", brackets);
	printf("%d Braces Left\n", braces);
	printf("%d Single Quotes Left\n", quote);
	printf("%d Double Quotes Left\n", quotes);
	printf("%d Comments Left\n", coment);
	printf("%d Asterisck double comments Left\n", asterisck);
	printf("%d Scape secuencies Left\n", bcb);

}
