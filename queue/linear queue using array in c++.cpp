#include <iostream>
using namespace std;

class queue
{
    private:
    int front,rear,size;
    int *s;
    public:
    queue(int size);
    void enqueue(int x);
    int dequeue();
    void display();
};

queue::queue(int size)
{
    front=rear=-1;
    this->size=size;
    s=new int[size];
}

void queue::enqueue(int x)
{
    if(rear==size-1)
    cout<<"queue is full.\n";
    else
    {
        rear++;
        s[rear]=x;
    }
}

int queue::dequeue()
{
    int x=-1;
    if(front==rear)
    cout<<"queue is empty.\n";
    else
    {
        x=s[front];
        front++;
    }
    return x;
}

void queue::display()
{
    int start=front,end=rear;
    while(start+1<=rear)
    {
        cout<<s[start+1]<<" ";
        start++;
    }
}

int main()
{
    queue q(10);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    return 0;
}
