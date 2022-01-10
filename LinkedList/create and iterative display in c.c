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
int count(struct node *q)
{
    struct node *p=q;
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}
int Delete(int index)
{
    struct node *p,*t;
    int x=-1;
    p=first;
    if(index<1 || index > count(p))
    return -1;
    if(index==1)
    {
        x=first->data;
        first=first->next;
        delete p;
        return x;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            t=p;
            p=p->next;
        }
        t->next=p->next;
        x=p->data;
        delete p;
        return x;
    }
}

bool issorted(struct node *q)
{
    struct node *p=q;
    int x=-65536;
    while(p!=NULL)
    {
        if(p->data<x)
        return false;
        x=p->data;
        p=p->next;
    }
    return true;
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
