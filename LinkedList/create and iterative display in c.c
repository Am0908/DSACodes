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

void display(struct node *p)
{
    struct node *t;
    t=p;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
}


int main()
{
    create(40);
    create(50);
    create(100);
    create(500);
    display(first);
    return 0;
}
