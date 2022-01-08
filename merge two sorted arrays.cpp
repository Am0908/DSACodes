#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cout<<"enter the size of first and second array:";
    cin>>n>>m;
    int a[n],b[m];
    int p=n+m;
    int c[p];

    cout<<"enter the first array elements:";
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"enter the second array elements:";
    for(int j=0;j<m;j++)
    cin>>b[j];

    int j=0,i=0,k=0;
    while(j<m&&i<n)
    {
        if(a[i]<b[j])
        c[k++]=a[i++];

        else
        c[k++]=b[j++];
    }
    for(;i<n;i++)
    c[k++]=a[i];

    for(;j<m;j++)
    c[k++]=b[j];

    for(i=0;i<p;i++)
    cout<<c[i]<<" ";
    return 0;
}
