#include <iostream>
#include <vector>
using namespace std;

//min heap

class priorityqueue
{
    vector<int> pq;

    public:

    priorityqueue()
    {

    }

    bool isempty()
    {
        return pq.size() == 0;
    }

    int getsize()       //return the size of priority queue
    {
        return pq.size();
    }

    int getmin()
    {
        if(isempty())
        return 0;       // priority queue is empty;
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childindex = pq.size() - 1;

        while(childindex > 0)
        {
            int parentindex = (childindex - 1)/2;

        if(pq[childindex] < pq[parentindex])
        {
            int temp = pq[parentindex];
            pq[parentindex] = pq[childindex];
            pq[childindex] = temp;
        }
        else
        break;

        childindex = parentindex;
        }

    }

    int removemin()
    {
        if(isempty())
        return 0;

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        //down heapify
        int parentindex=0, leftchildindex = 2 * parentindex + 1, rightchildindex= 2 * parentindex + 2 ;

        while(leftchildindex < pq.size())
        {
            int minindex=parentindex;
            if(pq[leftchildindex] < pq[minindex])
            minindex = leftchildindex;

            if(rightchildindex < pq.size() && pq[rightchildindex] < pq[minindex])
            minindex = rightchildindex;

            if(parentindex == minindex)
            break;

            int temp = pq[minindex];
            pq[minindex] = pq[parentindex];
            pq[parentindex] = temp;

            parentindex = minindex;
            leftchildindex= 2 * parentindex + 1;
            rightchildindex= 2 * parentindex + 2;
        }

        return ans;
    }

};

int main()
{
    priorityqueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout<<"Size of heap: "<<p.getsize()<<endl;
    cout<<"Minimum element: "<<p.getmin()<<endl;
    while(!p.isempty())
    {
        cout<<p.removemin()<<" ";
    }
    cout<<endl;
    cout<<"Size of heap: "<<p.getsize()<<endl;

    // we get elements in sorted order. so, it's actually heap sort.
    //for heap sort : Time complexity => O(n log n)
    //                space complexity => O(n)

    return 0;
}
