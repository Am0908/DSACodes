#include <iostream>
using namespace std;

int fibo_1(int n)
{
    if(n <= 1)
    return n;

    int a = fibo1(n-1);
    int b = fibo1(n-2);

    return a + b;
}

int fibo_2(int n)
{
    int* ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2; i <= n; i++)
    ans[i] = ans[i-1] + ans[i-2];

    return ans[n];
}

int main()
{
   int n;
   cin>>n;
   cout<<"Required fibonacci number: ";
   cout<<fibo_1(n);

    return 0;
}
