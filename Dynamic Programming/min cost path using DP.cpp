#include <iostream>
using namespace std;

int minCostPath_DP(int** input, int m, int n)
{
    int** output = new int*[n];
    for(int i = 0; i < m; i++)
    {
        output[i] = new int[m];
    }

    // fill the last cell i.e. destination
    output[m-1][n-1] = input[m-1][n-1];

    // fill last row (right to left)
    for(int j = n-2; j >= 0; j--)
    output[m-1][j] = output[m-1][j+1] + input[m-1][j];

    // fill last column (bottom to top)
    for(int i = m-2; i>=0; i--)
    output[i][n-1] = output[i+1][n-1] + input[i][n-1];

    for(int i = m-2; i>=0; i--)
    for(int j = n-2; j>=0; j--)
    output[i][j] = min(output[i][j+1], min(output[i+1][j+1], output[i+1][j])) + input[i][j];

    return output[0][0];
}

int main()
{
    int m, n;
    cin >> m >> n;
    int** input = new int *[m];
    for(int i = 0; i < m; i++)
    {
        input[i] = new int[m];
        for(int j = 0; j < n; j++)
        cin>>input[i][j];
    }

    cout << minCostPath_DP(input, m, n) << endl;
    return 0;
}
