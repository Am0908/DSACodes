#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *lchild;
  struct node *rchild;
} *root = NULL;

void iinsert (int x)
{
  struct node *t = root, *p, *r = NULL;
  if (root == NULL)
    {
      p = (struct node *) malloc (sizeof (struct node));
      p->data = x;
      p->lchild = p->rchild = NULL;
      root = p;
      return;
    }
  while (t != NULL)
    {
      r = t;
      if (t->data == x)
	return;
      else if (x < t->data)
	t = t->lchild;
      else
	t = t->rchild;
    }
  p = (struct node *) malloc (sizeof (struct node));
  p->data = x;
  p->lchild = p->rchild = NULL;
  if (p->data < r->data)
    r->lchild = p;
  else
    r->rchild = p;
}

struct node *recursiveinsert (struct node *p, int key)
{
  struct node *t;
  if (p == NULL)
    {
      t = (struct node *) malloc (sizeof (struct node));
      t->data = key;
      t->lchild = t->rchild = NULL;
      return t;
    }

  if (key < p->data)
    p->lchild = recursiveinsert (p->lchild, key);
  else if (key > p->data)
    p->rchild = recursiveinsert (p->rchild, key);

  return p;
}

struct node *isearch (int key)
{
  struct node *t = root;
  while (t != NULL)
    {
      if (t->data == key)
	return t;
      else if (key < t->data)
	t = t->lchild;
      else
	t = t->rchild;
    }
  return NULL;
}


struct node *rsearch (struct node *p, int key)
{
  if (p == NULL)
    return NULL;
  if (p->data == key)
    return p;
  else if (key < p->data)
    return rsearch (p->lchild, key);
  else
    return rsearch (p->rchild, key);
}

int height (struct node *p)
{
  int x, y;
  if (p == NULL)
    return 0;
  x = height (p->lchild);
  y = height (p->rchild);
  return x > y ? x + 1 : y + 1;
}

struct node *inpre(struct node *p)
{
    while(p && p->rchild != NULL)
    p=p->rchild;

    return p;
}

struct node *insucc(struct node *p)
{
    while(p && p->lchild != NULL)
    p=p->lchild;

    return p;
}

struct node *delete (struct node *p, int key)
{
  struct node *q;

    if(p==NULL)
    return NULL;
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        if(p==root)
        root=NULL;
        free(p);
        return NULL;
    }
    if (key < p->data)
      p->lchild = delete (p->lchild, key);
    else if (key > p->data)
      p->rchild = delete (p->rchild, key);
    else
    {
      if (height (p->lchild) > height (p->rchild))
	    {
	      q = inpre (p->lchild);
	      p->data = q->data;
	      p->lchild = delete (p->lchild, q->data);
	    }
      else
	    {
	      q = insucc (p->rchild);
	      p->data = q->data;
	      p->rchild = delete (p->rchild, q->data);
	    }
    }

    return p;
}

void inorder (struct node *p)
{
  if (p)
    {
      inorder (p->lchild);
      printf ("%d ", p->data);
      inorder (p->rchild);
    }
}

int main ()
{
  iinsert (10);
  iinsert (20);
  iinsert (30);
  iinsert (25);
  inorder (root);
  printf("\n");
  if (rsearch (root, 20))
    printf ("Found\n");
  else
    printf ("Not Found\n");
  delete(root,20);
  inorder(root);
  return 0;
}
