#include <iostream>

using namespace std;

int fibo_helper(int* ans, int n)
{
    if(n<=1)
    return n;

    //chcek if output already exists
    if(ans[n] != -1)
    return ans[n];

    int a = fibo_helper(ans, n-1);
    int b = fibo_helper(ans, n-2);

    //save ans for future use
    ans[n] = a + b;


    //return the final answer
    return ans[n];
}

int fibo(int n)
{
    int* ans = new int[n+1];
    for(int i=0;i<=n;i++)
    ans[i] = -1;

    return fibo_helper(ans, n);
}

int fibo_2(int n)
{
    if(n <= 1)
    return n;

    int a = fibo1(n-1);
    int b = fibo1(n-2);

    return a + b;
}

int main()
{
    int n;
    cin>>n;

    cout<<"Required fibonacci number: ";
    cout<<fibo(n);
    return 0;
}
