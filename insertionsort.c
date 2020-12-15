
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
      insertion_sort(N,list);
      printf("array after selection sort:-\n");
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

//logic of insertion sort

void insertion_sort(int N,int list[])
{
      int i,j,key;
      for(i=1;i<N;i++)
      {
            key=list[i];
            j=i-1;
            while(j>=0&&key<list[j])
            {
                  list[j+1]=list[j];
                  j=j-1;
            }
            list[j+1]=key;
      }
}
