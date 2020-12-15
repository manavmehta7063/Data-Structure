#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
typedef struct
{
    int info;
    struct node *link;
}node;
node *temp=NULL,*NEW=NULL,*first=NULL,*s=NULL;

void createnode();
void display();
void insert_ordered();

void main()
{
    int choice;
    printf("press 1 to create nodes\n");
    printf("press 2 to display nodes\n");
    printf("press 3 to insert ordered\n");
    printf("press 4 to exit\n");
    printf("enter the choice= ");
    scanf("%d",&choice);
    do
    {
        switch(choice)
        {
            case 1:createnode();
                   break;
            case 2:display();
                   break;
            case 3:insert_ordered();
                   break;
            default:exit(0);
                   break;
        }
        printf("press 1 to create nodes\n");
        printf("press 2 to display nodes\n");
        printf("press 3 to insert ordered\n");
        printf("press 4 to exit\n");
        printf("enter the choice= ");
        scanf("%d",&choice);
    }while(choice>0||choice<5);
}

void createnode()
{
    int n,i;
   printf("enter the number of node you want to create=");
   scanf("%d",&n);
   for(i=1;i<=n;i++)   // create n number of node
   {
    temp=(node*)malloc(sizeof(node));
    printf("enter the value in node= ");
    scanf("%d",&(temp->info));
    temp->link=NULL;
    if(first==NULL)
        first=temp;
    else
    {
        NEW=first;                //new points to first
        while(NEW->link!=NULL)    //check for last node in linked list
            NEW=NEW->link;
        NEW->link=temp;           //assigning the new node in the linked list
    }
   }
}

void display()
{
   if(first==NULL)
   {printf("The linkedlist is empty\n\n");}
   else
   { NEW=first;
     printf("Displaying the created node:-\n");
     while(NEW!=NULL)
     {
      if(NEW->link!=NULL)
      {  printf("%d->\t",NEW->info);
	     NEW=NEW->link;
      }
      else
      {  printf("%d->     NULL\n\n",NEW->info);
	     NEW=NEW->link;
      }
    }
    getch();
   }
}

void insert_ordered()
{
    temp=(node*)malloc(sizeof(node));
    printf("enter the value in node= ");
    scanf("%d",&(temp->info));
    temp->link=NULL;
    if(first==NULL)
    {
         first=temp;
    }
    else
    {

         NEW=first;
         s=first;
         while((NEW->link!=NULL)||((temp->info)<=(NEW->info))
         {
             NEW=NEW->link;
         }
         temp->link=NEW->link;
         NEW->link=temp;
    }
}
