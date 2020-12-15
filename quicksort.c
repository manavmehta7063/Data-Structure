
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
      quick_sort(list,0,N-1);
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

// logic of quick sort

void quick_sort(int list[],int lb,int ub)
{
      int i,j,key,flag=0;
      if(lb<ub)
      {
            i=lb;
            j=ub+1;
            key=list[lb];
            while(flag==0)
            {
                 i++;
                 while(list[i]<key)
                        i++;
                 while(list[j]>key)
                        j--;
                 if(i<j)
                        swap(&list[i],&list[j]);
                 else
                        flag=1;
            }
            swap(&list[lb],&list[j]);
            quick_sort(list,lb,j-1);
            quick_sort(list,j+1,ub);
      }
}
