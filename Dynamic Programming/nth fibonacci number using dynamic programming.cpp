#include <iostream>
using namespace std;

int fibo(int n)
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


//dynamic programming is bottom up approach and memoization is top down approach
//time complexities:
// memoization - O(n)
// Dp - O(n)
// Recursion - O(2^n)
