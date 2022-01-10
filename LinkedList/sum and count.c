int count(struct node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

int rcount(struct node *p)
{
    if(p!=NULL)
    return rcount(p->next)+1;
}

int sum(struct node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int rsum(struct node *p)
{
    if(p==NULL)
    return 0;
    return rsum(p->next)+p->data;
}
