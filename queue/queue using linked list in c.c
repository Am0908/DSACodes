#include <iostream>
using namespace std;

struct node
{
    public:
    int data;
    node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    if(front==NULL)
    front=rear=t;
    else
    {
        rear->next=t;
        rear=t;
    }
}

int dequeue()
{
    int x=-1;
    struct node *p=front;
    if(front==NULL)
    printf("Queue is empty.\n");
    else
    {
        x=front->data;
        front=front->next;
        free(p);
    }
    return x;
}


void display()
{
    struct node *p=front;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}
