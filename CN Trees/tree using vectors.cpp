#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class treenode
{
    public:
    T data;
    vector<treenode<T>*> children;

    treenode(T data)
    {
        this->data=data;
    }
};

treenode<int>* takeinput()
{
    int rootdata;
    cout<<"enter data:";
    cin>>rootdata;
    treenode<int>* root= new treenode<int>(rootdata);

    int n;
    cout<<"enter number of children:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        treenode<int>* child = takeinput();
        root->children.push_back(child);
    }
    return root;
}

void printree(treenode<int>*root)
{
    if(root==NULL)  //edge case as we will not pass a NULL root node.
    {
        cout<<"no nodes are present.";
        return;
    }
    cout<<root->data<<": ";

    for(int i=0;i<root->children.size();i++)
    cout<<root->children[i]->data<<", ";
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    printree(root->children[i]);
}

int main()
{
    /* treenode<int>* root= new treenode<int>(1);
       treenode<int>* node1= new treenode<int>(2);
       treenode<int>* node2= new treenode<int>(4);
       root->children.push_back(node1);
       root->children.push_back(node2); */


    //take input.
    treenode<int>* root= takeinput();

    //display the nodes.
    printree(root);

    //TODO delete the tree.


    return 0;
}
