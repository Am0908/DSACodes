#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    int height;
    int bf;
    struct node *rchild;
}*root=NULL;

int nodeheight(struct node *p)
{
    int hl,hr;
    hl=p && p->lchild ? p->lchild->height : 0;
    hr=p && p->rchild ? p->rchild->height : 0;
    return hl>hr?hl+1:hr+1;
}

int balancefactor(struct node *p)
{
    int hl,hr;
    hl=p && p->lchild ? p->lchild->height : 0;
    hr=p && p->rchild ? p->rchild->height : 0;
    return hl-hr;
}

struct node *LLRotation(struct node *p)
{
    struct node *pl=p->lchild;
    struct node *plr=p->rchild;

    pl->rchild=p;
    p->lchild=plr;
    p->height=nodeheight(p);
    pl->height=nodeheight(pl);

    if(root==p)
    root=pl;
    return pl;
}

struct node *LRRotation(struct node *p)
{
    struct node *pl=p->lchild;
    struct node *plr=pl->rchild;
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;

    pl->height=nodeheight(pl);
    p->height=nodeheight(p);
    plr->height=nodeheight(plr);

    if(root==p)
    root=plr;

    return plr;
}

struct node *RRRotation(struct node *p)
{
 int lbf,rbf;
 struct node *pr=p->rchild;
 pr->bf=0;
 p->rchild=pr->lchild;
 pr->lchild=p;
 lbf=nodeheight(p->lchild)+1;
 rbf=nodeheight(p->rchild)+1;
 p->bf=lbf-rbf;
 if(p==root)root=pr;
 return pr;
}
struct node *RLRotation(struct node *p)
{
 int lbf,rbf;
 struct node *pr=p->rchild;
 struct node *prl=pr->lchild;
 prl->bf=0;

 p->rchild=prl->lchild;
 pr->lchild=prl->rchild;
 prl->rchild=pr;
 prl->lchild=p;
 lbf=nodeheight(p->lchild)+1;
 rbf=nodeheight(p->rchild)+1;
 p->bf=lbf-rbf;

 lbf=nodeheight(pr->lchild)+1;
 rbf=nodeheight(pr->rchild)+1;
 pr->bf=lbf-rbf;
 if(p==root)root=prl;
 return prl;
}

struct node *recursiveinsert(struct node *p,int key)
{
    struct node *t;
    if(p==NULL)
    {
       t=(struct node*)malloc(sizeof(struct node));
       t->data=key;
       t->height=1;
       t->lchild=t->rchild=NULL;
       return t;
    }

    if(key<p->data)
    p->lchild=recursiveinsert(p->lchild,key);
    else if(key>p->data)
    p->rchild=recursiveinsert(p->rchild,key);

    p->height=nodeheight(p);

    if(balancefactor(p)==2 && balancefactor(p->lchild)==1)
        return LLRotation(p);
    else if(balancefactor(p)==2 && balancefactor(p->lchild)==-1)
        return LRRotation(p);
    else if(balancefactor(p)==-2 && balancefactor(p->rchild)==-1)
        return RRRotation(p);
    else if(balancefactor(p)==-2 && balancefactor(p->rchild)==1)
        return RLRotation(p);
    return p;
}

void Inorder(struct node *p)
{
 if(p)
 {
 Inorder(p->lchild);
 printf("%d ",p->data);
 Inorder(p->rchild);
 }
}

int main()
{
    root=recursiveinsert(root,20);
    root=recursiveinsert(root,10);
    root=recursiveinsert(root,5);
    Inorder(root);
    return 0;
}
