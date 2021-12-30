#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}

void enqueue(struct Queue *q,struct Node *x)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is Full");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

struct Node * dequeue(struct Queue *q)
{
    struct Node* x=NULL;
    if(q->front==q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
return x;
}

int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}

struct stack
{
    int size;
    int top;
    struct Node **s;
};

void stackcreate(struct stack *st,int size)
{
   st->size=size;
   st->top=-1;
   st->s=(struct Node **)malloc(st->size*sizeof(struct Node *));
}

void push(struct stack *st,struct Node *x)
{
    if(st->top==st->size-1)
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}

struct Node *pop(struct stack *st)
{
    struct Node *x=NULL;
    if(st->top==-1)
    printf("Stack Underflow\n");
    else
    {
        x=st->s[st->top--];
    }
    return x;
}

int isemptystack(struct stack st)
{
    if(st.top==-1)
    return 1;
    return 0;
}

int isfullstack(struct stack st)
{
    return st.top==st.size-1;
}

struct Node *root=NULL;

void Treecreate()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
    printf("Enter root value ");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("enter left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct
            Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("enter right child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct
            Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}
void Preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void ipreorder(struct Node *p)
{
    struct stack stk;
    stackcreate(&stk,100);
    while(p||!isemptystack(stk))
    {
        if(p)
        {
            printf("%d ",p->data);
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            p=p->rchild;
        }
    }
}

void iinorder(struct Node *p)
{
    struct stack stk;
    stackcreate(&stk,100);
    while(p||!isemptystack(stk))
    {
        if(p)
        {
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }
}

int main()
{
Treecreate();
printf("\nPre Order ");
Preorder(root);
printf("\nInOrder ");
Inorder(root);
printf("\nPost Order ");
Postorder(root);

printf("\nIterative preorder ");
ipreorder(root);
printf("\nIterative inorder ");
iinorder(root);

return 0;
}
