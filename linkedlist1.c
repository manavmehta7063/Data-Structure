
#include<stdio.h>
#include<malloc.h>
#include<process.h>
#include<conio.h>
struct node
{
   int info;
   struct node *link;
};
struct node *temp=NULL,*p=NULL,*New=NULL,*first=NULL;



void insert_end();
void insert_anypos();
void insert_beginning();
void createnode();
void displaynode();



void main()
{
   int choice;
   printf("1 to insert node at beginning\n");
   printf("2 to insert node at ending\n");
   printf("3 to enter the node at any position\n");
   printf("4 to create node\n");
   printf("5 to display linkedlist\n");
   printf("6 to exit\n");
   printf("Enter your choice=");
   scanf("%d",&choice);
   do
   {
    switch(choice)
	 {
	    case 1 :insert_beginning();
		     break;
	    case 2 :insert_end();
		     break;
	    case 3 :insert_anypos();
		     break;
	    case 4 :createnode();
		     break;
	    case 5 :displaynode();
		     break;
	    default : exit(0);
		     break;

	 }
     printf("1 to insert node at beginning\n");
     printf("2 to insert node at ending\n");
     printf("3 to insert node at any position\n");
     printf("4 to create node\n");
     printf("5 to display linkedlist\n");
     printf("6 to exit\n ");
     printf("Enter your choice=");
     scanf("%d",&choice);
   }while(choice>0&&choice<7);
}

void insert_anypos()
{
     int pos,i;
     struct node *save,*pre;
     New=(struct node*)malloc(sizeof(struct node));
     printf("Enter data in node:-\n");
     scanf("%d",&(New->info));
     if(first==NULL)
     {
	first=New;
     }
     else
     {
	printf("\nEnter the location you want to insert new node=");
	scanf("%d",&pos);
	if(pos==1)
	{
	  New->link=first;
	  New=first;
	}
	else
	{
	  save=first;
	  for(i=0;i<pos-1;i++)
	  {
	       pre=save;
	       save=save->link;
	  }
	  pre->link=New;
	  New->link=save;
	}
     }
}




void insert_end()
{  struct node *save;
   New=(struct node*)malloc(sizeof(struct node));
   printf("Enter data in node:-\n");
   scanf("%d",&(New->info));
   if(first==NULL)
   {
      first=New;
   }
   else
   {
      save=first;
      while(save->link!=NULL)
      {
	    save=save->link;
      }
      save->link=New;
   }
}




void insert_beginning()
{
    New=(struct node*)malloc(sizeof(struct node));
    printf("Enter data in node:-\n");
    scanf("%d",&(New->info));
    if(first==NULL)
    {
       New->link=first;
       first=New;
    }
    else
    {
      New->link=first;
      first=New;
    }
}





void createnode()
{
   int n,i;
   printf("enter the number of node you want to create=");
   scanf("%d",&n);
   for(i=1;i<=n;i++)   // create n number of node
   {
      temp=(struct node*)malloc(sizeof(struct node)); // create node
      printf("enter data in %d node:-",i);
      scanf("%d",&(temp->info));
      temp->link=NULL;

      if(first==NULL)    // first node of linklist
	  first=temp;
      else             // linklist is already created
      {
	    p=first;
	    while(p->link!=NULL)
	    p=p->link;
	    p->link=temp;
      }
   }
}





void displaynode()
{
   if(first==NULL)
   {printf("The linkedlist is empty\n\n");}
   else
   { p=first;
     printf("Displaying the created node:-\n");
     while(p!=NULL)
     {
      if(p->link!=NULL)
      {  printf("%d->\t",p->info);
	     p=p->link;

      }
      else
      {  printf("%d->     NULL\n\n",p->info);
	     p=p->link;
      }
    }
    getch();
   }

}

