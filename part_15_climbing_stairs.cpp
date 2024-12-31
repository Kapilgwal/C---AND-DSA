#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return climbStairs(n - 1) + climbStairs(n - 2);
}

int climbStairsMem(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    return dp[n];
}

int climbStairsTab(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int climbStairsSpcOpm(int n)
{
    int prev1 = 1;
    int prev2 = 1;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n = 4;
    cout << climbStairs(n) << endl;
    vector<int> dp(n + 1, -1);
    cout << climbStairsMem(n, dp) << endl;
    cout << climbStairsTab(n) << endl;
    cout << climbStairsSpcOpm(n) << endl;

    return 0;
}