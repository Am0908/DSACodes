#include <iostream>
#include <queue>
using namespace std;

void klargestelements(int arr[], int n, int k)
{
    priority_queue<int> pq;

    for(int i=0; i<n; i++)
    {
        pq.push(arr[i]);
    }
    int i=0;
    while(i<k)
    {
        cout<<pq.top()<<" ";
        pq.pop();
        i++;
    }
}

int main()
{
    int arr[] = {10, 2, 5, 1, 4};
    int k=3;
    klargestelements(arr, 5, k);

    return 0;
}
