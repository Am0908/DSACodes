#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*head=NULL,*last=NULL;

class linkedlist
{
    public:
    void create(int x);
    void display();
};

void linkedlist::create(int x)
{
    node *t;
    t=new node;
    t->data=x;
    t->next=NULL;
    if(head==NULL)
    head=last=t;
    else
    {
      last->next=t;
      last=t;
    }
}

void linkedlist::display()
{
    node *p=head;
    cout<<"Linked List: ";
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    linkedlist l1;
    l1.create(5);
    l1.create(6);
    l1.display();
    return 0;
}
