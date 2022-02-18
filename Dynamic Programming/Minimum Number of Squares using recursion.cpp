//using recursion

#include <iostream>
using namespace std;
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
const int N = 1e3+2, MOD = 1e9+7;

int MinSquare(int n)
{
    if(n == 1 || n == 2 || n == 3)
    return n;

    int ans = MOD;
    for(int i = 1; i*i <= n; i++)
    ans = min(ans, 1 + MinSquare(n-i*i));

    return ans;
}

signed main()
{
    int n;
    cin>>n;
    cout<<MinSquare(n)<<endl;
    return 0;
}
