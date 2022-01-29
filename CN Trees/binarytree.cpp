#include <iostream>
#include <queue>
using namespace std;

template<typename T>
struct binarynode
{
    T data;
    struct binarynode *lchild;
    struct binarynode *rchild;
    binarynode(T data)
    {
        this->data=data;
        lchild=NULL;
        rchild=NULL;
    }
    ~binarynode()
    {
        delete lchild;
        delete rchild;
    }
};

void printtree(binarynode<int>* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" :";
    if(root->lchild!=NULL)
    cout<<" L "<<root->lchild->data;
    if(root->rchild!=NULL)
    cout<<" R "<<root->rchild->data;
    cout<<endl;
    printtree(root->lchild);
    printtree(root->rchild);
}

binarynode<int>* takeinput()
{
    int rootdata;
    cout<<"Enter root data :";
    cin>>rootdata;
    if(rootdata==-1)
    return NULL;
    queue<binarynode<int>*> q;
    binarynode<int>* root = new binarynode<int>(rootdata);
    q.push(root);
    while(q.size()!=0)
    {
        binarynode<int>* temp = q.front();
        q.pop();
        cout<<"Enter left child of "<<temp->data<<" :";
        int x;
        cin>>x;
        if(x!=-1)
        {
            binarynode<int>* newnode1 = new binarynode<int>(x);
            temp->lchild=newnode1;
            q.push(newnode1);
        }
        cout<<"Enter right child of "<<temp->data<<" :";
        cin>>x;
        if(x!=-1)
        {
            binarynode<int>* newnode2 = new binarynode<int>(x);
            temp->rchild=newnode2;
            q.push(newnode2);
        }
    }
    return root;
}

int countnode(binarynode<int>* root)
{
    if(root==NULL)
    return 0;

    return countnode(root->lchild) + countnode(root->rchild) + 1;
}

void printlevelwise(binarynode<int>* root)
{
    if(root==NULL)  //edge case as we will not pass a NULL root node.
    {
        cout<<"no nodes are present.";
        return;
    }
    queue<binarynode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        binarynode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<" : ";

        if(front->lchild!=NULL)
	    {
	        cout<<" L "<<front->lchild->data;
	        pendingnodes.push(front->lchild);
	    }
	    if(front->rchild!=NULL)
	    {
	        cout<<" R "<<front->rchild->data;
	        pendingnodes.push(front->rchild);
	    }

	    cout<<endl;
    }
}

bool isnodepresent(binarynode<int>* root,int x)
{
    if(root==NULL)
    return false;
    if(root->data==x)
    return true;
    int res1=isnodepresent(root->lchild,x);
    if(res1)
    return true;
    int res2=isnodepresent(root->rchild,x);
    return res2;
}

void preorder(binarynode<int>* root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(binarynode<int>* root)
{
    if(root)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        cout<<root->data<<" ";
    }
}

void mirrortree(binarynode<int>* root)
{
    if(root==NULL)
    return;
    else
    {
        mirrortree(root->lchild);
        mirrortree(root->rchild);
        binarynode<int>* temp = root->lchild;
        root->lchild=root->rchild;
        root->rchild=temp;
    }
}

int main()
{
    binarynode<int>* root = takeinput();
    postorder(root);
    return 0;
}
