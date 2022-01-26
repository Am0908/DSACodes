#include <iostream>
#include <vector>
#include <queue>
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

treenode<int>* takeinputlevelwise()
{
    int rootdata;
    cout << "enter root data:";
    cin >> rootdata;
    treenode<int>* root = new treenode<int>(rootdata);
    queue<treenode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size() != 0)
    {
        treenode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout << "enter number of children of "<< front->data<<": ";
        int numchild,childdata;
        cin >> numchild;
        for(int i=0;i<numchild;i++)
        {
            cout << "enter the " << i<< " child of "<<front->data<<": ";
            cin>>childdata;
            treenode<int>* child = new treenode<int>(childdata);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
}

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

void printreelevelwise(treenode<int>*root)
{
    if(root==NULL)  //edge case as we will not pass a NULL root node.
    {
        cout<<"no nodes are present.";
        return;
    }
    queue<treenode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(!pendingnodes.empty())
    {
        treenode<int>* front = pendingnodes.front();
        pendingnodes.pop();
        cout<<front->data<<" : ";
	  for(int i=0;i<front->children.size();i++)
        {
            cout <<  front->children[i]->data << ',' ;
            pendingnodes.push(front->children[i]);
        }
        cout<<endl;
    }
}

int numofnodes(treenode<int>* root)
{
    int ans=1;
    for(int i=0;i<root->children.size();i++)
    ans+=numofnodes(root->children[i]);
    return ans;
}


int sumofnodes(treenode<int>* root)
{
    int sum = root->data;
    for(int i = 0 ; i < root->children.size() ; i++)
    {
        sum += sumofnodes(root->children[i]);
    }
    return sum;
}

int findheight(treenode<int>* root)
{
    int max=0;
    for(int i=0;i<root->children.size();i++)
    {
        int height=findheight(root->children[i]);
        if(height>max)
        max=height;
    }
    return max+1;
}

int main()
{
    /* treenode<int>* root= new treenode<int>(1);
       treenode<int>* node1= new treenode<int>(2);
       treenode<int>* node2= new treenode<int>(4);
       root->children.push_back(node1);
       root->children.push_back(node2); */

    //take input.
    treenode<int>* root= takeinputlevelwise();

    //display the nodes.
    printreelevelwise(root);

    // Total number of nodes.
    cout<<"number of nodes: "<<numofnodes(root)<<endl;

    return 0;
}
