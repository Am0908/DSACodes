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

void levelorder(struct Node *root)
{
    struct Queue q;
    create(&q,100);
    printf("%d ",root->data);
    enqueue(&q,root);
    while(!isEmpty(q))
    {
      root=dequeue(&q);
      if(root->lchild)
      {
          printf("%d ",root->lchild->data);
          enqueue(&q,root->lchild);
      }
      if(root->rchild)
      {
          printf("%d ",root->rchild->data);
          enqueue(&q,root->rchild);
      }
    }
}

int count(struct Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int nodewith2children(struct Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=nodewith2children(p->lchild);
        y=nodewith2children(p->rchild);
    if(p->lchild&&p->rchild)
    return x+y+1;
    else
    return x+y;
    }
    return 0;
}

int height(struct Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=height(p->lchild);
        y=height(p->rchild);
    if(x>y)
    return x+1;
    else
    return y+1;
    }
    return 0;
}

int leafnode(struct Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=leafnode(p->lchild);
        y=leafnode(p->rchild);
    if(p->lchild==NULL&&p->rchild==NULL)
    return x+y+1;
    else
    return x+y;
    }
    return 0;
}

int nonleafnodes(struct Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=nonleafnodes(p->lchild);
        y=nonleafnodes(p->rchild);
    if(p->lchild!=NULL||p->rchild!=NULL)
    return x+y+1;
    else
    return x+y;
    }
    return 0;
}

int nodeswithdegree1(struct Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=nodeswithdegree1(p->lchild);
        y=nodeswithdegree1(p->rchild);
    if(p->lchild!=NULL^p->rchild!=NULL)
    return x+y+1;
    else
    return x+y;
    }
    return 0;
}

int numofnodes(struct Node *p)
{
    if(p==NULL)
    return 0;
    return numofnodes(p->lchild)+numofnodes(p->rchild)+1;
}

int leafnodes(struct Node *p)
{
    if(p==NULL)
    return 0;
    if(!p->lchild&&!p->rchild)
    return leafnodes(p->lchild)+leafnodes(p->rchild)+1;
    else
    return leafnodes(p->lchild)+leafnodes(p->rchild);
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

printf("\nLevel Order:");
levelorder(root);

printf("\nNo. of Nodes:");
printf("%d",count(root));

printf("\nNum. of nodes having both the children:");
printf("%d",nodewith2children(root));

printf("\nHeight of Tree:");
printf("%d",height(root));

printf("\nLeaf Nodes:");
printf("%d",leafnode(root));

printf("\nNon-Leaf Nodes:");
printf("%d",nonleafnodes(root));

printf("\nNodes with degree 1:");
printf("%d",nodeswithdegree1(root));

printf("\nNo. of nodes:");
printf("%d",numofnodes(root));

printf("\nNo. of Leaf Nodes:");
printf("%d",leafnodes(root));
return 0;
}
