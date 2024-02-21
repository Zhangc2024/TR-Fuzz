/* c-examples by A.Shtanyuk */
/* pointers_misc.c - a mixture of pointers */
int main()
{
   int v1=0;
   int *v2=&v1;
   int v3[]={1,2,3,4,5,6,7};
   int *v4[]={&v3[0],&v3[1],&v3[2]};
   int v5[3][2]={{1,1},{2,2},{3,3}};
   int (*v6)[2]=&v5[1];
   int (*v7[2])[2]={&v5[0],&v5[2]};
   int (*(*p)[2])[2]=&v7;
   return 0;
}
