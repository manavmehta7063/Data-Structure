#include<stdio.h>
#include<conio.h>
void main()
{
      int list[10];
      int N,i;
      printf("enter the number of element you want to insert=");
      scanf("%d",&N);
      printf("enter the element in array:-\n");
      for(i=0;i<N;i++)
      {
            scanf("%d",&list[i]);
      }
      bubble_sort(N,list);
      printf("array after bubble sort:-\n");
      display_list(N,list);
}
void display_list(int N,int list[])
{
      int i;
      for(i=0;i<N;i++)
            printf("%d\n",list[i]);
}
void swap(int *a,int *b)
{
      int temp;
      temp=*a;
      *a=*b;
      *b=temp;
}

// logic of bubble sort****

void bubble_sort(int N,int list[])
{     int i,j;
      for(i=0;i<N-1;i++)
      {
            for(j=0;j<N-i-1;j++)
            {
                  if(list[j]>list[j+1])
                  {
                        swap(&list[j],&list[j+1]);
                  }
            }
      }
}
