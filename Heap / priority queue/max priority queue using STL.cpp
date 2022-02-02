#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(5);
    pq.push(10);
    pq.push(20);
    pq.push(25);
    pq.push(50);
    pq.push(40);

    cout << "Size: " << pq.size() << endl;
    cout << "Top: "<< pq.top() << endl;
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
