#include <iostream>
using namespace std;

int knapsack(int* weight, int* values,int n, int maxweight)
{
    //base case
    if(n == 0 || maxweight == 0)
    return 0;

    //recursive calls

    if(weight[0] > maxweight)
    return knapsack(weight + 1, values + 1, n - 1, maxweight);
    int x = knapsack(weight + 1, values + 1, n - 1, maxweight - weight[0]) + values[0];
    int y = knapsack(weight + 1, values + 1, n - 1, maxweight);

    return max(x, y);
}

int main()
{
    int n = 5;
    int weight[] = {5, 1, 8, 9, 2};
    int values[] = {4, 10, 2, 3, 1};
    int w = 15;

    cout<<knapsack(weight, values, n, w);
    return 0;
}
