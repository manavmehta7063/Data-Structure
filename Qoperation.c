#include<stdio.h>
#include<conio.h>
#include<process.h>
int front=-1,rear =-1;
int Q[100];
void qpush(int);
void qpop();
void displayQ();
void main()
{
    int max,choice;
    printf("enter number of element you want to insert=");
    scanf("%d",&max);
    printf("PRESS 1 TO PUSH ELEMENT IN QUEUE\n");
    printf("PRESS 2 TO POP ELEMENT IN QUEUE\n");
    printf("PRESS 3 TO DISPLAY ELEMENT IN QUEUE\n");
    printf("PRESS 4 TO EXIT\n");
    printf("enter your choice= ");
    scanf("%d",&choice);
    do
    { switch(choice)
       {
           case 1:qpush(max);
                  break;
           case 2:qpop();
                  break;
           case 3:displayQ();
                  break;
           default: exit(0);
                  break;
       }
         printf("PRESS 1 TO PUSH ELEMENT IN QUEUE\n");
         printf("PRESS 2 TO POP ELEMENT IN QUEUE\n");
         printf("PRESS 3 TO DISPLAY ELEMENT IN QUEUE\n");
         printf("PRESS 4 TO EXIT\n");
         printf("enter your choice= ");
         scanf("%d",&choice);
   }while(choice>0||choice<5);
}

void qpush(int max)
{
    int item;
    if(rear==max-1)
     {
        printf("THE QUEUE IS OVER FLOW\n");
        getch();
     }
    else
    {
        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else
            rear=rear+1;
        printf("enter the value you want to insert= ");
        scanf("%d",&item);
        Q[rear]=item;
    }
}

void qpop()
{
    int item;
    if(front==-1)
        printf("THE QUEUE IS UNDER FLOW\n");
    else
    {
        item=Q[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=front+1;
        }
        printf("\n\n%d  is deleted \n\n",item);
    }
}

void displayQ()
{
    if(front==-1)
    {
        printf("QUEUE IS UNDERFLOW\n");
    }
    else
    {
        printf("\nTHE ELEMENTS IN THE QUEUE ARE \n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d\n\n",Q[i]);
        }
    }
}
