#include <bits/stdc++.h>
using namespace std;

int solveRec(int m, int n, int i, int j)
{
    if (i == m - 1 and j == n - 1)
    {
        return 1;
    }

    if (i >= m or j >= n)
    {
        return 0;
    }

    return solveRec(m, n, i + 1, j) + solveRec(m, n, i, j + 1);
}

int uniquePath(int m, int n)
{
    int i = 0;
    int j = 0;
    return solveRec(m, n, i, j);
}

int solveMemo(int m, int n, int i, int j, vector<vector<int>> &dp)
{
    if (i == m - 1 and j == n - 1)
    {
        return 1;
    }

    if (i >= m or j >= n)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = solveMemo(m, n, i + 1, j, dp) + solveMemo(m, n, i, j + 1, dp);
    return dp[i][j];
}

int uniquePathMemo(int m, int n)
{
    int i = 0;
    int j = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solveMemo(m, n, i, j, dp);
}

int uniquePathTab(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; 
            }
        }
    }

    return dp[m - 1][n - 1];
}

int main()
{

    int m = 3;
    int n = 2;

    int ans1 = uniquePath(m, n);
    int ans2 = uniquePathMemo(m, n);
    int ans3 = uniquePathTab(m, n);
    cout << ans1 << " " << ans2 << " " << ans3 << endl;

    return 0;
}