void insert_end(int x)
{
    struct node *p=first,*t;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    p->next=t;
}

void insert_starting(int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=first;
    first=t;
}

void insert_after_a_given_element(int x,int y)
{
    struct node *p=first,*t;
    int val;
    while(p->data!=y)
    {
        val=p->data;
        p=p->next;
    }
    if(p!=NULL ||(p==NULL&&val==y))
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
    else
    printf("Node not found!");
}
