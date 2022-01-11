#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
}*top=NULL;

void push(int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    if(t==NULL)
    printf("stack is full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

void display()
{
    struct node *t;
    t=top;
    printf("Stack :\n\n");
    while(t!=NULL)
    {
        printf("| %d |\n|____|\n",t->data);
        t=t->next;
    }
    printf("\n");
}

int pop()
{
    struct node *t;
    int x=-1;
    if(top==NULL)
    printf("stack is empty\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}



int main()
{
    push(10);
    push(20);
    display();
    pop();
    printf("\n");
    display();
    push(40);
    push(50);
    push(70);
    push(80);
    display();
    return 0;
}
