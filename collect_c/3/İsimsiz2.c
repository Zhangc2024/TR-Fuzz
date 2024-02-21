#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define x 2

struct meyve
{
	char ad[100];
	float agirlik;
	char form[100];
	int sayi;
	float birim_fiyati;
	char mehm[100];
};


struct sepet
{
	struct meyve meyve_1;
	struct meyve meyve_2;
};



void sepet_isteme(struct sepet *box)
{
	printf("1. meyvenin adini giriniz: ");
	scanf("%s",box->meyve_1.ad);
	fflush(stdin);
	printf("2. meyvenin adini giriniz: ");
	scanf("%s",box->meyve_2.ad);
	
	fflush(stdin);
	//printf("%s",box.meyve_1.ad);
}



void meyve_isteme(struct meyve fruit[],struct sepet box)
{
	//printf("%s",box.meyve_2.ad);
	int i;
	for(i=0;i<x;i++)
	{
		/*if(i==0)
		{
		printf("--------%s--------\n",box.meyve_1.ad);
		}
		else
		{
		printf("--------%s--------\n",box.meyve_2.ad);
		}*/
		    if(i==0)
		    {            
		    strcpy(fruit[i].ad,box.meyve_1.ad);
		    }
		    else
		    {
		    strcpy(fruit[i].ad,box.meyve_2.ad);
		    }
		
			printf("%d. Meyvenin agirligini giriniz: ",i+1);
			scanf("%f",&fruit[i].agirlik);
			printf("%d.Meyvenin formunu giriniz: ",i+1);
			scanf("%s",fruit[i].form);
		    fflush(stdin);
		    printf("***%s***",fruit[i].form);
			printf("%d.Meyvenin sayisini giriniz : ",i+1);
			scanf("%d",&fruit[i].sayi);
			printf("%d.Meyvenin birim fiyatini giriniz: ",i+1);
			scanf("%f",&fruit[i].birim_fiyati);
			
	}
}


void fiyat(struct meyve *fruit,float *borc)
{
	int i;
	
	//float borc;

		borc[i]=(fruit->agirlik)*(fruit->birim_fiyati)*(fruit->sayi);
		if((fruit->agirlik)<=200 && (fruit->form)!="yuvarlak")
		{
		*(borc+i)=*(borc+i);
		}
		if((fruit->form)=="yuvarlak" && (fruit->agirlik)<=200)
		{
			*(borc+i)=2**(borc+i);
		}
		if((fruit->agirlik)>200 && (fruit->form)=="yuvarlak")
		{
		*(borc+i)=2**(borc+i)+3;
		}
		if((fruit->agirlik)>200 && (fruit->form)!="yuvarlak")
		{
		*(borc+i)=*(borc+i)+3;
		}  
		printf("%.2f\n",*(borc+i));
	//bastirma(fruit,borc);
		

}	


void bastirma(struct meyve *fruit,float *borc)
{
	int i;
	printf("\nTAPUR SUNAR\n");
	printf("%s meyve %f fiyatla satilmistir\n",fruit->ad,*borc);
}

	
int main() 
{
	int i;
	//int meyve_sayisi;
	//printf("Toplam meyve sayisini giriniz: ");
	//scanf("%d",&meyve_sayisi);
	float borc[2]={};
	struct sepet box;
	//struct meyve temp;
	struct meyve fruit[x];
	
	sepet_isteme(&box);
	meyve_isteme(fruit,box);
	for(i=0;i<x;i++)
	{
	fiyat(&fruit[i],&borc[i]);
	}
	for(i=0;i<x;i++)
	{	
	bastirma(&fruit[i],&borc[i]);
	}
	return 0;
}
