#include <stdio.h>
#include <ctype.h>
#include <string.h>
main(){
	char string[]=" In large-scale environments, robots should have proper internal representation of the surroundings for achieving tasks such as localization, navigation, and exploration. Internal representations could be categorized in two ways: metric (grid-based) map and topological map. In this paper, we aim to generate a topological map representation (collision-free graph) of the large-scale environment from its metric map. The metric map is constructed by using laser range data with grid-line intersection algorithm. After metric map is obtained, spectral clustering is applied.";
	char word[1000];
	char *tokenPtr;
	tokenPtr=strtok(string," ");
 	char a;
 	while(tokenPtr!=NULL){
 		if(*tokenPtr=='m' ||*tokenPtr=='M' ||*tokenPtr=='T' ||*tokenPtr=='t'){
 			printf("%s\n",tokenPtr);
		 }
 		tokenPtr=strtok(NULL," ");
	 }
	
	
}
