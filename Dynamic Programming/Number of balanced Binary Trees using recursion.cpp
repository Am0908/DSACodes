#include <iostream>
using namespace std;

int balancedbst(int h)
{
    if(h<=1)
    return 1;

    int x = balancedbst(h-1);
    int y = balancedbst(h-2);

    int mod = (int) (pow(10,9)) +7;
    int temp1 =(int) (((long)(x) * x )% mod);
    int temp2 = (int) ((2* (long) (x) * y) % mod);

    int ans =(temp1 + temp2) % mod;
    return ans;
}

int main()
{
    int height;
    cin>>height;
    cout<<balancedbst(height);
    return 0;
}
