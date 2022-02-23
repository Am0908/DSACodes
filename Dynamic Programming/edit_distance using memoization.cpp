#include <iostream>
using namespace std;

int edit_distance_mem(string s, string t, int** output)
{
    int m = s.size();
    int n = t.size();

    //base case
    if(s.size() == 0 || t.size() == 0)
    return max(s.size(), t.size());

    //check if answer already exists
    if(output[m][n] != -1)
    return output[m][n];

    //recursive calls
    int ans;

    if(s[0] == t[0])
    ans = edit_distance_mem(s.substr(1), t.substr(1), output);

    else
    {
        //insert
        int x = edit_distance_mem(s.substr(1), t, output) + 1;
        //delete
        int y = edit_distance_mem(s, t.substr(1), output) + 1;
        //replace
        int z = edit_distance_mem(s.substr(1), t.substr(1), output) + 1 ;

        ans = min(x, min(y, z));
    }
    output[m][n] = ans;
    return ans;
}

int edit_distance_mem(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int** output = new int*[m+1];
    for(int i = 0; i <= m; i++)
    {
        output[i] = new int[n+1];
        for(int j = 0; j <= n; j++)
        output[i][j] = -1;
    }

    return edit_distance_mem(s, t, output);
}

int main()
{
    string s, t;
    cin>>s>>t;
    cout<<edit_distance_mem(s, t);
    return 0;
}
