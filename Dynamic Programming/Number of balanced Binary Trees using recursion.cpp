#include <iostream>
using namespace std;

int balancedbst(int h)
{
    if(h<=1)
    return 1;

    int x = balancedbst(h-1);
    int y = balancedbst(h-2);

    int ans = x * x + 2 * x * y;
    return ans % 1000000007 ;
}

int main()
{
    int height;
    cin>>height;
    cout<<balancedbst(height);
    return 0;
}
