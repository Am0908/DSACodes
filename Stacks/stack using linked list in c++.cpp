#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};

class stack
{
    private:
    node *top;
    public:
    stack(){top=NULL;}
    void push(int x);
    int pop();
    void display();
};

void stack::push(int x)
{
    node *t;
    t=new node;
    if(t==NULL)
    cout<<"stack is full\n";
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

void stack::display()
{
    node *t;
    t=top;
    cout<<"stack\n\n";
    while(t)
    {
        cout<<"| "<<t->data<<" |\n"<<"|"<<"____"<<"|\n";
        t=t->next;
    }
    cout<<"\n";
}

int stack::pop()
{
    int x=-1;
    if(top!=NULL)
    {
        node *t=top;
        x=t->data;
        top=top->next;
        free(t);
    }
    else
    cout<<"stack underflow";
    return x;
}
int main()
{
    stack st;
    st.push(10);
    st.push(20);
    st.display();
    st.pop();
    st.display();
    return 0;
}
