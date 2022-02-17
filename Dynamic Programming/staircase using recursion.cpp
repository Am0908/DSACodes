// Algorithm:

// Create a recursive function (count(int n)) which takes only one parameter.
// Check the base cases. If the value of n is less than 0 then return 0, and if the value of n is equal to zero then return 1 as it is the starting stair.
// Call the function recursively with values n-1, n-2 and n-3 and sum up the values that are returned, i.e. sum = count(n-1) + count(n-2) + count(n-3)
// Return the value of the sum.



#include <iostream>
using namespace std;

int staircase(int n)
{
    if(n == 0)
    return 1;

    if(n < 0)
    return 0;

    return staircase(n-3) + staircase(n-2) + staircase(n-1);
}

int main()
{
    int n;
    cin>>n;
    cout<<staircase(n);
    return 0;
}
