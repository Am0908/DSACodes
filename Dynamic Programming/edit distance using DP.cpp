#include <iostream>
using namespace std;

int edit_distance_DP(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int** output = new int*[m+1];
    for(int i = 0; i <= m; i++)
    {
        output[i] = new int[n+1];
    }

    // fill the first row
    for(int j = 0; j <= n; j++)
    output[0][j] = j;

    //fill the first column
    for(int i = 0; i <= m; i++)
    output[i][0] = i;

    for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++)
    {
        if(s[m-i] == t[n-j])
        output[i][j] = output[i-1][j-1];

        else
        output[i][j] = min(output[i-1][j-1], min(output[i][j-1], output[i-1][j])) + 1;

    }
    return output[m][n];
}

int main()
{
    string s, t;
    cin>>s>>t;
    cout<<edit_distance_DP(s, t);
    return 0;
}
