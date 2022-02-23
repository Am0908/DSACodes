#include <iostream>
using namespace std;

int edit_distance(string s, string t)
{
    //base case
    if(s.size() == 0 || t.size() == 0)
    return max(s.size(), t.size());

    if(s[0] == t[0])
    return edit_distance(s.substr(1), t.substr(1));

    else
    {
        //insert
        int x = edit_distance(s.substr(1), t) + 1;
        //delete
        int y = edit_distance(s, t.substr(1)) + 1;
        //replace
        int z = edit_distance(s.substr(1), t.substr(1)) + 1 ;

        return min(x, min(y, z));
    }
}

int main()
{
    string s, t;
    cin>>s>>t;
    cout<<edit_distance(s, t);
    return 0;
}
//time complexity: O(3^n)
