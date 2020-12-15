#include<stdio.h>
#include<conio.h>
#include<process.h>
int front=-1,rear=-1;
int CQ[100];
int n;
void CQPUSH();
void CQPOP();
void display();
void main()
{
     int choice;
     printf("enter the number of element you want to insert= ");
     scanf("%d",&n);
     printf("press 1 for push element\n ");
     printf("press 2 for pop element\n ");
     printf("press 3 for display elements in queue\n ");
     printf("press 4 for exit\n ");
     printf("enter your choice= ");
     scanf("%d",&choice);
     do
     {
         switch(choice)
         {
             case 1:CQPUSH();
                    break;
             case 2:CQPOP();
                    break;
             case 3:display();
                    break;
            default:exit(0);
                    break;
         }
         printf("\npress 1 for push element\n ");
         printf("press 2 for pop element\n ");
         printf("press 3 for display elements in queue\n ");
         printf("press 4 for exit\n ");
         printf("enter your choice= ");
         scanf("%d",&choice);
     }while(choice>0||choice<5);
}


void CQPUSH()
{
    int item;
    if((front==-1&&rear==n-1)||(front==rear+1))
    {
        printf("THE CIRCULAR QUEUE IS OVERFLOW\n");
    }
    else
    {
        if(rear==-1)
            front=rear=0;
        else if(rear==n-1)
            rear=0;
        else
            rear=rear+1;
    }
    printf("enter element to push= ");
    scanf("%d",&item);
    CQ[rear]=item;
}


void CQPOP()
{
   int item;
   if(front==-1)
   {
       printf("THE QUEUE IS UNDERFLOW\n");
   }
   else
   {
       item=CQ[front];
       if(front==rear)
       {
           front=rear=-1;
       }
       else if(front==n-1)
       {
           front=0;
       }
       else
       {
           front=front+1;
       }
   }
   printf("%d is poped\n",item);
}
void display()
{
     if(front==-1)
     {
         printf("THE QUEUE IS UNDERFLOW\n");
     }
     else
     {
         for(int i=front;i<=rear;i++)
         {
             printf("\t%d\n",CQ[i]);
         }

     }
}
