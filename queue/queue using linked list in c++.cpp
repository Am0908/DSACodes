#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};

class queue
{
    private:
    node *front;
    node *rear;
    public:
    queue();
    void enqueue(int x);
    int dequeue();
    void display();
};

queue::queue()
{
    front = nullptr;
    rear = nullptr;
}
void queue::enqueue(int x)
{
    node *t;
    t=new node;
    t->data=x;
    if(front==NULL)
    front=rear=t;
    else
    {
        rear->next=t;
        rear=t;
    }
}

int queue::dequeue()
{
    node *p;
    int x=-1;
    if(front==NULL)
    cout<<"queue is empty.\n";
    else
    {
        p=front;
        x=p->data;
        front=front->next;
        delete p;
    }
    return x;
}

void queue::display()
{
    node *p=front;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}

int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
}
