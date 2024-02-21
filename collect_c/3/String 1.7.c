#include <stdio.h>
#include <ctype.h>
#include <string.h>
main(){
	char string[]="In large-scale environments, robots should have proper internal representation of the surroundings for achieving tasks such as localization, navigation, and exploration. Internal representations could be categorized in two ways: metric (grid-based) map and topological map. In this paper, we aim to generate a topological map representation (collision-free graph) of the large-scale environment from its metric map. The metric map is constructed by using laser range data with grid-line intersection algorithm. After metric map is obtained, spectral clustering is applied.";
	char word[1000];
	int i=0,j=0,k=0;
	while(string[i]!='\0'){
		if(string[i]==' '){
			if(string[i+1]=='t' || string[i+1]=='T' || string[i+1]=='m' || string[i+1]=='M'){
				j=i+1;
				while(isalnum(string[j])){
					printf("%c",string[j]);
					word[k]=string[j];
					j++;
					k++;
			
				}
				word[k]=' ';
				printf("\n");
				k++;
			}
		}
		i++;
	}
	word[k]='\0';
	printf("\n%s",word);
	
	
}
