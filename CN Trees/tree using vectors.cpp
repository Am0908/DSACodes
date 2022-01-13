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

int main()
{
    treenode<int>* root= new treenode<int>(1);
    treenode<int>* node1= new treenode<int>(2);
    treenode<int>* node2= new treenode<int>(4);
    root->children.push_back(node1);
    root->children.push_back(node2);
    return 0;
}
