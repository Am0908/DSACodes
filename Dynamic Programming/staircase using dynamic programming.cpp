// staircase using dynamic programming

// Algorithm:

// Create an array of size n + 1 and initialize the first 3 variables with 1, 1, 2. The base cases.
// Run a loop from 3 to n.
// For each index i, computer value of ith position as dp[i] = dp[i-1] + dp[i-2] + dp[i-3].
// Print the value of dp[n], as the Count of the number of ways to reach n th step.

#include <iostream>

using namespace std;

int countways(int n)

{
    int res[n+1];

    res[0] = 1;
    res[1] = 1;
    res[2] = 2;

    for(int i = 3; i <= n; i++)
    res[i] = res[i-1] + res[i-2] + res[i-3];

    return res[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<countways(n);
    return 0;
}
