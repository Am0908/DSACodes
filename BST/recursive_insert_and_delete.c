struct node *recursiveinsert(struct node *p,int key)
{
    struct node *t;
    if(p==NULL)
    {
       t=(struct node*)malloc(sizeof(struct node));
       t->data=key;
       t->lchild=t->rchild=NULL;
       return t;
    }

    if(key<p->data)
    p->lchild=recursiveinsert(p->lchild,key);
    else if(key>p->data)
    p->rchild=recursiveinsert(p->rchild,key);

    return p;
}
