#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    for(int i=0;i<n-1;i++)
    {
        int k=i;
        for(int j=i; j<n;j++)
        {
            if(arr[j]<arr[k])
            k=j;
        }
        swap(arr[i],arr[k]);
    }

    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}
