#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
typedef struct
 {
     int info;
     struct node *link;
 }node;
 node *temp=NULL,*p=NULL,*New=NULL,*first=NULL;
 void search_node();
 void count_node();
 void create_node();
 void display_node();
 void delete_node();
 void main()
 {
     int choice;
     printf(" 1 to search node\n 2 to count node\n ");
     printf("3 to create node\n 4 to display node\n ");
     printf("5 to delete node\n 6 to exit\n ");
     printf("enter your choice=");
     scanf("%d",&choice);
     do
     {
         switch(choice)
         {
         case 1:search_node();
             break;
         case 2:count_node();
             break;
         case 3:create_node();
             break;
         case 4:display_node();
             break;
         case 5:delete_node();
             break;
         default:exit(0);
             break;
         }
         printf(" 1 to search node\n 2 to count node\n ");
         printf("3 to create node\n 4 to display node\n ");
         printf("5 to delete node\n 6 to exit\n ");
         printf("enter your choice=");
         scanf("%d",&choice);
     }while(choice>0&&choice<7);
 }
 void search_node()
 {
     int count=1;
     int n;
     printf("enter the value you want to search=");
     scanf("%d",&n);
     temp=(node *)malloc(sizeof(node));
     if(first==NULL)
         printf("The link is empty\n");
     else
     {
         temp=first;
         while((temp->info!=n)&&(temp->link!=NULL))
         {   temp=temp->link;
             count++;   }
         if(temp->info!=n)
             printf("Node is not found in list \n");
         else
             printf("Node is found at position %d\n",count);

     }
 }
 void count_node()
 {
     int count=0;
     temp=(node *)malloc(sizeof(node));
     if(first==NULL)
         printf("The link is empty\n");
     else
     {   temp=first;
         while(temp->link!=NULL)
         {   count++;
             temp=temp->link;   }
         printf("The number of nodes are %d\n",count);
     }
 }
 void create_node()
 {
     int n,i;
   printf("enter the number of node you want to create=");
   scanf("%d",&n);
   for(i=1;i<=n;i++)   // create n number of node
   {
      temp=( node*)malloc(sizeof( node)); // create node
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
 void display_node()
 {   if(first==NULL)
         printf("The list is empty\n\n");
     else
     {   p=first;
         printf("Displaying the created node:-\n");
         while(p!=NULL)
         {   if(p->link!=NULL)
             {   printf("%d->\t",p->info);
	             p=p->link;   }
             else
             {   printf("%d->\tNULL\n\n",p->info);
	             p=p->link;   }
         }
         getch();
     }
 }
 void delete_node()
 {   int po,y;
     node *temp,*ptr;
     temp=(node *)malloc(sizeof(node));
     printf("enter element you want to delete=");
     scanf("%d",&po);
     if(first==NULL)
         printf("The list is empty\n");
     else
     {
         temp=first;
         while((temp->info!=po)&&(temp->link!=NULL))
         {   ptr=temp;
             temp=temp->link;   }
         if(temp->info!=po)
             printf("node not found\n");
         else
         {   y=temp->info;
             ptr->link=temp->link;   }
     }
}


