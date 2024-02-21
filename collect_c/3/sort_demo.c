/* c-examples by A.A.Shtanyuk */
/* sort_demo.c */

#include <stdio.h>       
#include <stdlib.h>  
#include <time.h> 

// обмен значениями
void swap(int *A, int *B)
{
   int T=*A;
   *A=*B;
   *B=T;
} 
// Пузырьковая сортировка       
void BubbleSort(int *a, int N)
{
   int i,j;
   for(i=0;i<N-1;i++)
      for(j=N-1;j>i;j--)
        if(a[j-1]>a[j])
           swap(&a[j-1],&a[j]);
}
// Сортировка выбором
void SelectionSort(int *a, int N)
{
      int i,j,index;
      for(i=0;i<N-1;i++)
      {
         index=i;
         for(j=i+1;j<N;j++)
            if(a[j]<a[index])
               index=j;
         swap(&a[i],&a[index]);			
      }
}
// Сортировка вставками
void InsertionSort(int *a, int N)
{
      int i,j;
      int temp;
      for(i=1;i<N;i++)
      {
         j=i;
         temp=a[i];
         while(j>0 && temp<a[j-1])
         {
            a[j]=a[j-1];
            j--;
         }
         a[j]=temp;
      }
}
// Быстрая сортировка
void QuickSort(int* a, int p, int r)
{
      int i,j;
      int x;
      i=p;
      j=r;
      x=a[(i+j)/2];
      do
      {
         while(a[i]<x) i++;
         while(a[j]>x) j--;
         if(i<=j)
         {
            swap(&a[i],&a[j]);
            i++;
            j--;
         }
       }
       while(i<=j);
       if(j>p)
         QuickSort(a,p,j);
       if(i<r)
         QuickSort(a,i,r);
}
// Выполнение программы начинается здесь :-)
int main()
{
    int *arr,i;
    // Размер массива (подходит для быстрой сортировки, 
    // в остальных случаях слишком велик!
    const int N=800000;
    // переменные для хранения отсчётов времени
    clock_t begin,end;
    // инициализируем генератор ПСЧ
    srand(time(0));
    // создаём динамический массив средствами C
    arr=(int*)malloc(N*sizeof(int));
    // заполняем массив числами от 0 до 9
    for(i=0;i<N;i++)
      arr[i]=rand()%10;

    // засекаем начальный момент времени
    begin=clock();
    // вызываем функцию быстрой сортировки (а можно любую другую)
    QuickSort(arr,0,N-1);
    // фиксируем момент окончания
    end=clock();
    // время сортировки выводим на экран (в сек.)
    printf("Time=%.1fc\n",(float)(end-begin)/CLOCKS_PER_SEC);
    return 0;
}
