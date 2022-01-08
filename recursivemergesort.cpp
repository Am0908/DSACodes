#include <iostream>
using namespace std;

void Merge(int A[],int l,int mid,int h)
{
 int i=l,j=mid+1,k=l;
 int B[100];

 while(i<=mid && j<=h)
 {
 if(A[i]<A[j])
 B[k++]=A[i++];
 else
 B[k++]=A[j++];
 }
 for(;i<=mid;i++)
 B[k++]=A[i];
 for(;j<=h;j++)
 B[k++]=A[j];

 for(i=l;i<=h;i++)
 A[i]=B[i];
}
void MergeSort(int A[],int l,int h)
{
 int mid;
 if(l<h)
 {
 mid=(l+h)/2;
 MergeSort(A,l,mid);
 MergeSort(A,mid+1,h);
 Merge(A,l,mid,h);

 }
}
int main()
{
    int n,m;
    m=n/2;
    cout<<"enter the size of the array:";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array:";
    for(int i=0;i<n;i++)
    cin>>arr[i];

    MergeSort(arr,0,n-1);

    cout<<"sorted array is:";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}
