// minimum steps to one using memoization

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int minsteps_helper(int n, int* ans)
{
    //base case
    if(n <= 1)
    return 0;

    //check if output already exists
    if(ans[n] != -1)
    return ans[n];

    //calculate output
    int x = minsteps_helper(n-1, ans);

    int y = INT_MAX, z = INT_MAX;

    if(n % 2 == 0)
    y = minsteps_helper(n/2, ans);

    if(n % 3 == 0)
    z = minsteps_helper(n/3, ans);

    int output = min(x, min(y, z)) + 1;

    ans[n] = output;

    return output;
}

int minsteps(int n)
{
    int* ans = new int[n+1];
    for(int i = 0; i <= n; i++)
    ans[i] = -1;

    return minsteps_helper(n, ans);
}

int main()
{
    int n;
    cin>>n;
    cout<<"minimum steps to one: ";
    cout<<minsteps(n);
    return 0;
}
