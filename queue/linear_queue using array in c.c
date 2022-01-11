// in case of one pointer => the queue moves one step. i.e. every element move one step backwards.
// while in case of two pointers => the counter moves one step every time a person goes out.
// i.e. front moves one step forward when an element is deleted.
// when front==rear => queue is empty.


#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size,front,rear;
    int *s;
};

void create(struct queue *q,int size)
{
    q->size=size;
    q->rear=q->front=-1;
    q->s=(int *)malloc(q->size*sizeof(int));
}

void enqueue(struct queue *q,int x)
{
    if(q->rear==q->size-1)
    printf("Queue is full.\n");
    else
    {
        q->rear++;
        q->s[q->rear]=x;
    }
}

int dequeue(struct queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    printf("queue is empty.\n");
    else
    {
        x=q->s[q->front];
        q->front++;
    }
    return x;
}

void display(struct queue q)
{
    while(q.front+1<=q.rear)
    {
        printf("%d ",q.s[q.front+1]);
        q.front++;
    }
    printf("\n");
}
int main()
{
    struct queue q;
    create(&q,10);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    display(q);
    dequeue(&q);
    display(q);
    return 0;
}
