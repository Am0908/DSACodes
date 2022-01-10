void search(int x)
{
    struct node *p;
    p=first;
    while(p)
    {
        if(p->data==x)
        {
            printf("Found the element!");
            break;
        }
        p=p->next;
    }
    if(p==NULL)
    printf("Node not found!");
}
