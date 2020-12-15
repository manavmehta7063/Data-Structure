
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
      selection_sort(N,list);
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

// logic of selection sort****

void selection_sort(int N,int list[])
{
      int i,j;
      for(i=0;i<N-1;i++)
      {
            for(j=i+1;j<N;j++)
            {
                  if(list[i]>list[j])
                  {
                        swap(&list[i],&list[j]);
                  }
            }
      }
}
