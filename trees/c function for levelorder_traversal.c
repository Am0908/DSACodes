void levelorder(struct Node *root)
{
    struct Queue q;
    create(&q,100);
    printf("%d ",root->data);
    enqueue(&q,root);
    while(!isEmpty(q))
    {
      root=dequeue(&q);
      if(root->lchild)
      {
          printf("%d ",root->lchild->data);
          enqueue(&q,root->lchild);
      }
      if(root->rchild)
      {
          printf("%d ",root->rchild->data);
          enqueue(&q,root->rchild);
      }
    }
}
