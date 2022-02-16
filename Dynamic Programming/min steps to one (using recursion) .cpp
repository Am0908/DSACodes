#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int minsteps(int n)
{
    // base case
    if(n <= 1)
    return 0;

    //recursive call
    int x = minsteps(n-1);

    int y = INT_MAX, z = INT_MAX;

    if(n % 2 == 0)
    y = minsteps(n/2);

    if(n % 3 == 0)
    z = minsteps(n/3);

    int ans = min(x, min(y, z));

    return ans + 1;

}

int main()
{
    int n;
    cin>>n;
    cout<<minsteps(n)<<endl;

    return 0;
}
