#include <stdio.h>

struct node
{
    struct node *lchild;
    int data;
    int height;
    struct node *rchild;
}*root=NULL;

int nodeheight(struct node *p)
{
    int hl,hr;
    hl=p && p->lchild ? lchild->height : 0;
    hr=p && p->rchild ? rchild->height : 0;
    return hl>hr?hl+1:hr+1;
}

int balancefactor(struct node *p)
{
    int hl,hr;
    hl=p && p->lchild ? lchild->height : 0;
    hr=p && p->rchild ? rchild->height : 0;
    return hl-hr;
}

struct node *recursiveinsert(struct node *p,int key)
{
    struct node *t;
    if(p==NULL)
    {
       t=(struct node*)malloc(sizeof(struct node));
       t->data=key;
       t->height=1;
       t->lchild=t->rchild=NULL;
       return t;
    }

    if(key<p->data)
    p->lchild=recursiveinsert(p->lchild,key);
    else if(key>p->data)
    p->rchild=recursiveinsert(p->rchild,key);

    p->height=nodeheight(p);

    if(balancefactor(p)==2 && balancefactor(p->lchild)==1)
        return LLRotation(p);
    else if(balancefactor(p)==2 && balancefactor(p->lchild)==-1)
        return LRRotation(p);
    else if(balancefactor(p)==-2 && balancefactor(p->rchild)==-1)
        return RRRotation(p);
    else if(balancefactor(p)==-2 && balancefactor(p->rchild)==1)
        return RLRotation(p);
    return p;
}

int main()
{
    printf("Hello World");

    return 0;
}
