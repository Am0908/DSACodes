#include <iostream>
using namespace std;

int balancedbst(int h)
{
  if(h<=1)
 return 1;

 int x = balancedbst(h-1);
 int y = balancedbst(h-2);

 int temp1 = x * x % 1000000007;
 int temp2 = 2 * x * y % 1000000007;

 int ans = temp1 + temp2;
 return ans;
}

int main()
{
    int height;
    cin>>height;
    cout<<balancedbst(height);
    return 0;
}
