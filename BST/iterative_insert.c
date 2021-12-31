void insert(struct Node *t,int key)
{
    struct Node *r=NULL,*p;
    while(t!=NULL)
    {
        r=t;
        if(key==t->data)
        return;
        else if(key<t->data)
        t=t->lchild;
        else
        t=t->rchild;
    }
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(p->data<r->data)
    r->lchild=p;
    else
    r->rchild=p;
}
