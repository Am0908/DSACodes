bool issorted(struct node *q)
{
    struct node *p=q;
    int x=-65536;
    while(p!=NULL)
    {
        if(p->data<x)
        return false;
        x=p->data;
        p=p->next;
    }
    return true;
}
