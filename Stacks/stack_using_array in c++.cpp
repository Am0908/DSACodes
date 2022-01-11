#include <iostream>
using namespace std;

class stack
{
    private:
    int size;
    int top;
    int *s;

    public:
    void create(int size);
    void push(int x);
    int pop();
    void display();
    int peek(int index);
    int isfull();
    int isempty();
    int stacktop();
    ~stack();
};

void stack::create(int size)
{
    this->size=size;
    top=-1;
    s=new int[size];
}

void stack::push(int x)
{
    if(top<size-1)
    {
        top++;
        s[top]=x;
    }
    else
    cout<<"stack overflow\n";
}

int stack::pop()
{
    int x=-1;
    if(top==-1)
    cout<<"stack underflow!\n";
    else
    {
        x=s[top];
        top--;
    }
    return x;
}

void stack::display()
{
    while(top>-1)
    {
        cout<<s[top]<<" ";
        top--;
    }
    cout<<"\n";
}

int stack::peek(int index)
{
    int x = -1;
    if (top-index+1 < 0 || top-index+1 == size){
        cout << "Invalid position!" << endl;
    } else {
        x = s[top-index+1];
    }
    return x;
}

int stack::isfull()
{
    if(top==size-1)
    return 1;
    return 0;
}

int stack::isempty()
{
    return (top==-1);
}

int stack::stacktop()
{
    if(top>-1)
    return s[top];
    else
    return -1;
}

stack::~stack()
{
    delete[] s;
}
int main()
{
    stack st;
    st.create(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.display();
    return 0;
}
