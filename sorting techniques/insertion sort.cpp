#include <iostream>
using namespace std;
int main()
{
    int arr[5]={3,6,1,8,2};
    for(int i=1;i<5;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    for(int i=0;i<5;i++)
    cout<<arr[i];
    return 0;
}
