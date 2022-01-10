int max(struct node *p)
{
    int max=0;
    while(p)
    {
        if(p->data>max)
        max=p->data;
        p=p->next;
    }
    return max;
}

int rmax(struct node *p)
{
    int x=0;
    if(p==NULL)
    return INT_MIN;
    x=rmax(p->next);
    if(x>p->data)
    return x;
    else return p->data;
}
