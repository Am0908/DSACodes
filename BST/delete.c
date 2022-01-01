struct node *Delete(struct node *p,int key)
{
    if(p==NULL)
    return NULL;
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        if(p==root)
        root=NULL;
        free(p);
        return NULL;
    }
    if(key<p->data)
    p->lchild=Delete(p->lchild,key);
    else if(key>p->data)
    p->rchild=Delete(p->rchild,key);
    else
    {
        if(height(p->lchild)>height(p->rchild))
        {
            q=inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=insucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
}
