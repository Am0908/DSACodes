#include <iostream>
using namespace std;

void inplace_heapsort(int pq[], int n)
{
    //build heap in the input array.
    for(int i = 1 ; i < n ; i++)
    {
        int childindex = i;

        while(childindex > 0)
        {
            int parentindex = (childindex - 1)/2;

            if(pq[childindex] > pq[parentindex])
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

    //remove elements
    int size = n;
 while(size>1)
 {
    int temp = pq[0];
    pq[0] = pq[size - 1];
    pq[size-1] = temp;

    size--;

    int parentindex=0;
    int leftchildindex = 2 * parentindex + 1;
    int rightchildindex= 2 * parentindex + 2 ;

    while(leftchildindex < size)
    {
        int minindex=parentindex;

        if(pq[leftchildindex] > pq[minindex])
        minindex = leftchildindex;

        if(rightchildindex < size && pq[rightchildindex] > pq[minindex])
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
 }

}

int main()
{
    int input[] = { 10, 5, 40, 20, 25};
    inplace_heapsort(input, 5);
    for(int i = 0; i < 5; i++)
    cout<<input[i]<<" ";
    cout<<endl;
    return 0;
}
