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
struct node *temp=NULL,*L=NULL,*R=NULL,*New=NULL;
void insert_beginning();
void insert_end();
int create_node();
int display_node();
int main()
{
    int choice;
    printf("1 to insert node at beginning\n2 to insert node at ending\n");
    printf("3 to create node\n4 to display node\n5 to exit\n");
    printf("enter the choice=");
    scanf("%d",&choice);
    do
    {
        switch(choice)
        {
        case 1:insert_beginning();
            break;
        case 2:insert_end();
            break;
        case 3:create_node();
            break;
        case 4:display_node();
            break;
        default:exit(0);
            break;
        }
        printf("\n1 to insert node at beginning\n2 to insert node at ending\n");
        printf("3 to create node\n4 to display node\n5 to exit\n");
        printf("enter the choice=");
        scanf("%d",&choice);
    }while(choice>0&&choice<6);
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
        printf("enter value at node=");
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

void insert_end()
{

    temp=(struct node *)malloc(sizeof(struct node));
        printf("enter value at node=");
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

void insert_beginning()
{

    temp=(struct node *)malloc(sizeof(struct node));
        printf("enter value at node=");
        scanf("%d",&temp->info);
        temp->lptr=NULL;
        temp->rptr=NULL;
        if(L==NULL)
        {
            L=R=temp;
        }
        else
        {
            temp->lptr=NULL;
            temp->rptr=L;
            L->lptr=temp;
            L=temp;
        }
}
