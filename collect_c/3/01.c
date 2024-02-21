//1-masala
#include <stdio.h>
int  main()
{
    char s[50]="Salom dunyo";
    int i, k=0, d=1;
    for (i=0; s[i]!='\0'; i++)
    {
	    if(s[i]==' ' || s[i]=='\n' || s[i]=='\t')
        {
            d++;
        }
        k++;
    }
    printf("So'zlarning soni %d ta\n", d);
    return 0;
}



// //2-masala
// #include <stdio.h>
// #include <string.h>
// int  main()
// {
// 	char text[30];
//  printf("So'zni kiriting: ");
// 	scanf("%s",text);
// 	int son=0,k=0, i, j;
// 	char unli[10]={'a', 'e', 'u', 'i', 'o'};
// 	for (i=0; i<strlen(text); i++)
// 		son=0;
// 	{
// 		for(j=0; j<strlen(unli);j++)
// 		{
// 			if(text[i]!=unli[j])
// 			{ son++; }
// 		}
// 		if (son==5)
// 		{ k++; }
// 	}
// 	if (k!=0)
// 	{ 
// 		printf("Undosh harflar %d ta\n",k); 
// 	}
// 	else
// 	{
// 		printf("Undosh harf yoq\n");
// 	}
//      return 0;
// }



// //3-masala
// #include <stdio.h>
// #include <string.h>
// int  main()
// {
// 	char a[30],k=0, i, j;
// 	printf("text: "); scanf("%s",a);
// 	char unli[10]={'a', 'e', 'u', 'i', 'o'};

// 	for (i=0; a[i]!='\0'; i++)
// 	{
// 		for (j=0; a[j]!='\0'; j++)
// 		{
// 			if (a[i]!=unli[j])
// 			{ k++; }	
// 			else
// 			{
// 				printf("%c",a[i]);
// 			}
// 		}
// 		if (k!=0)
// 		{
// 			printf("%c",a[i]);
// 		}
// 	}
// 	printf("\n");
// 	return 0;
// }



// //6-masala
// #include <stdio.h>
// #include <string.h>
// int  main()
// {
// 	char soz[10],a[1];
// 	printf("so'z kriting: "); 
// 	scanf("%s",soz);
// 	int d=0,f=0, i, j;
// 	for (i=0; soz[i]!='\0'; i++)
// 	{
// 		d++;
// 	}
// 	for (j=0; j<d/2; j++)
// 	{
// 		a[f]=soz[j];
// 		soz[j]=soz[d-j-1];
// 		soz[d-j-1]=a[f];
// 	}
// 	printf("%s\n",soz);
// 	return 0;
// 	}