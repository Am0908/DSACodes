#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*first=NULL,*last=NULL;

void create(int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    first=last=t;
    else
    {
        last->next=t;
        last=t;
    }
}

void display()
{
    struct node *t;
    t=first;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
}

void search(int x)
{
    struct node *p;
    p=first;
    while(p)
    {
        if(p->data==x)
        {
            printf("Found the element!");
            break;
        }
        p=p->next;
    }
    if(p==NULL)
    printf("Node not found!");
}

void insert_end(int x)
{
    struct node *p=first,*t;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    p->next=t;
}

void insert_starting(int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=first;
    first=t;
}

void insert_after_a_given_element(int x,int y)
{
    struct node *p=first,*t;
    int val;
    while(p->data!=y)
    {
        val=p->data;
        p=p->next;
    }
    if(p!=NULL ||(p==NULL&&val==y))
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
    else
    printf("Node not found!");
}

int main()
{
    create(40);
    create(50);
    create(100);
    create(500);
    insert_end(125);
    insert_end(200);
    insert_starting(25);
    insert_after_a_given_element(2500,300);
    display();
    return 0;
}
