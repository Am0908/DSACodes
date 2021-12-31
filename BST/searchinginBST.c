struct Node *rsearch(struct Node *t,int key)
{
    if(t==NULL)
    return NULL;
    if(key==t->data)
    return t;
    else if(key<t->data)
    return rsearch(t->lchild,key);
    else
    return rsearch(t->rchild,key);
}
