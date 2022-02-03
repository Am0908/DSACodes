#include <iostream>
#include <queue>
using namespace std;

void ksmallestelements(int arr[], int n, int k)
{
    priority_queue<int> pq;

    for(int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for(int i = k; i < n; i++)
    {
        if(arr[i] < pq.top())
        {
            pq.push(arr[i]);
            pq.pop();
        }
    }

    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}

int main()
{
    int arr[] = {10, 2, 3, 1, 4};
    int k=3;
    ksmallestelements(arr, 5, k);

    return 0;
}
