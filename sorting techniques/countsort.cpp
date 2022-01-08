#include <iostream>
using namespace std;

int findmax(int arr[],int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }
    return max;
}
void countsort(int arr[], int n)
{
    int max;
    int *c;
    max=findmax(arr,n);
    c=new int[max+1];
    for(int i=0;i<max+1;i++)
    c[i]=0;

    for(int i=0;i<n;i++)
    c[arr[i]]++;
    int i=0,j=0;
    while(i<max+1)
    {
        if(c[i]>0)
        {
            arr[j++]=i;
            c[i]--;
        }
        else
        i++;
    }
}
int main()
{
    int n;
    cout<<"enter the size of the array:";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array:";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    countsort(arr,n);
    cout<<"sorted array is:";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}
