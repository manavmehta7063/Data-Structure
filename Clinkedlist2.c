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
int main()
{
    int choice;

    printf("\n1 to create node\n2 to display node\n3 to insert node at any position\n4 to exit\n");
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
        default:exit(0);
            break;
        }
        printf("\n1 to create node\n2 to display node\n3 to insert node at any position\n4 to exit\n");
        printf("enter the choice=");
        scanf("%d",&choice);
    }while(choice>0&&choice<5);
    return 0;
}
int create_node()
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
int display_node()
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
void insert_anypos()
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
