#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<malloc.h>
 struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};
struct node *temp=NULL,*L=NULL,*R=NULL,*New=NULL,*pre=NULL;
int create_node();
int display_node();
void insert_anypos();
void search_node();
void count_node();
void delete_node();
int main()
{
    int choice;

    printf("\n1 to create node\n2 to display node\n3 to insert node at any position\n4 to search node \n5 to count node \n6 to delete node \n7 to exit\n");
    printf("enter the choice=");
    scanf("%d",&choice);
    do
    {
        switch(choice)
        {
        case 1:create_node();
            break;
        case 2:display_node();
            break;
        case 3:insert_anypos();
            break;
        case 4:search_node();
            break;
        case 5:count_node();
            break;
        case 6:delete_node();
            break;
        default:exit(0);
            break;
        }
        printf("\n1 to create node\n2 to display node\n3 to insert node at any position\n4 to search node \n5 to count node \n6 to delete node \n7 to exit\n");
        printf("enter the choice=");
        scanf("%d",&choice);
    }while(choice>0&&choice<8);
    return 0;
}
int create_node()    //already written in previous program
{
    int n,i;
    printf("enter the number of nodes you want in doubly linked list=");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        printf("enter the value of node=");
        scanf("%d",&temp->info);
        temp->lptr=NULL;
        temp->rptr=NULL;
        if(L==NULL)
        {
            L=R=temp;
        }
        else
        {
            temp->rptr=NULL;
            temp->lptr=R;
            R->rptr=temp;
            R=temp;
        }
    }
   return 0;
}
int display_node()   //already written in previous program
{
    temp=(struct node *)malloc(sizeof(struct node));
    if(L==NULL)
        printf("The list is empty");
    else
    {
        printf("The number of element are :-\n");
        temp=L;
        while(temp!=NULL)
        {
            if(temp->rptr!=NULL)
            {
                printf("%d->\t",temp->info);
                temp=temp->rptr;
            }
            else
            {
                printf("%d->\tNULL",temp->info);
                break;
                getch();
            }
       }
    }
   return 0;
}
void insert_anypos() //already written in previous program
{
    int n,i;
    printf("enter the position you want to insert new node=");
    scanf("%d",&n);
    temp=(struct node *)malloc(sizeof(struct node));
    printf("enter the value of node=");
    scanf("%d",&temp->info);
    if(L==NULL)
        printf("The link is empty");
    else
    {
        New=L;
        for(i=0;i<n-1;i++)
        {
            pre=New;
            New=New->rptr;
        }
        New->lptr=temp;
        pre->rptr=temp;
        temp->lptr=pre;
        temp->rptr=New;
    }
}
void search_node()
{
    int n,count=1;
    printf("enter the value you want to search in node=");
    scanf("%d",&n);
    if(L==NULL)
        printf("The link is empty");
    else
    {
        temp=L;
        while((temp->info!=n)&&(temp->rptr!=NULL))
        {
            temp=temp->rptr;
            count++;
        }
        if(temp->info!=n)
            printf("Node is not found");
        else
            printf("Node is found at position %d = %d",count,temp->info);
    }
}
void count_node()
{
    int count=0;
    if(L==NULL)
        printf("The link is empty");
    else
    {
        temp=L;
        while(temp!=NULL)
        {
            temp=temp->rptr;
            count++;
        }
        printf("There are total %d nodes in doubly linked list",count);
    }
}
void delete_node()
{
    int i,n;
    printf("enter the number you want to delete=");
    scanf("%d",&n);
    if(L==NULL)
        printf("The link is empty");
    else
    {
        temp=L;
        while((temp->info!=n)&&(temp->rptr!=NULL))
        {
            pre=temp;
            temp=temp->rptr;
        }
        if(temp->info!=n)
            printf("value not found in list");
        else
        {
            pre->rptr=temp->rptr;
            temp->lptr=pre;
        }
    }
}
