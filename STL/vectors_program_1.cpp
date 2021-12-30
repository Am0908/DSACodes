#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v={10,20,40,50};
    v.push_back(55);
    v.pop_back();
    v.push_back(100);
    v.push_back(125);
    v.push_back(500);
    v.push_back(10000);
    for(int x:v)
    cout<<x<<" ";
    return 0;
}
