#include <stdio.h>
#include <ctype.h>

struct hasta_bilgileri{
	char ad[100];
	char soyad[100];
	char tel_no[100];
	char kan_grubu[100];
	int yas;
	
	
};

main(){
	
	int size,i;
	char c;
	printf("Hasta sayisini giriniz: \n");
	scanf("%d",&size);
	
	
	struct hasta_bilgileri hasta[size];
	for(i=0;i<size-1;i++){
		printf("Hastanin adini giriniz: ");
		scanf(" %s",&hasta[i].ad);


	}
/*	for(i=0;i<size;i++){
		printf("Hastanin adini giriniz: ");
		gets(hasta[i].ad);
		
		
	}*/
	for(i=0;i<size;i++){
		printf("%s\n",hasta[i].ad);	
		
	}
	
	
}
