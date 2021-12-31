
//*****************not working******************

void iinsert(struct Node *,int key)
{
    struct Node *t;
    if(p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->rchild=t->lchild=NULL;
    }
    if(key<p->data)
    {
        p->lchild=iinsert(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=iinsert(p->rchild,key);
    }
    return t;
}
