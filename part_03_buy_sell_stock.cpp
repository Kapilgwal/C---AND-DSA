#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solveRec(vector<int> prices, int n, int idx, int buy)
{
    if (idx >= n)
    {
        return 0;
    }
    int profit = INT_MIN;
    if (buy)
    {
        int buyK = -prices[idx] + solveRec(prices, n, idx + 1, 0);
        int skip = solveRec(prices, n, idx + 1, 1);
        profit = max(buyK, skip);
    }

    else
    {
        int sell = prices[idx] + solveRec(prices, n, idx + 1, 1);
        int skip = solveRec(prices, n, idx + 1, 0);
        profit = max(sell, skip);
    }

    return profit;
}

int maxProfit(vector<int> prices, int n)
{
    int idx = 0;
    int buy = 1;
    return solveRec(prices, n, idx, buy);
}

int solveMem(vector<int> prices, int n, int idx, int buy, vector<vector<int>> &dp)
{
    if (idx >= n)
    {
        return 0;
    }

    if (dp[idx][buy] != -1)
    {
        return dp[idx][buy];
    }
    int profit = INT_MIN;
    if (buy)
    {
        int buyK = -prices[idx] + solveMem(prices, n, idx + 1, 0, dp);
        int skip = solveMem(prices, n, idx + 1, 1, dp);
        profit = max(buyK, skip);
    }

    else
    {
        int sell = prices[idx] + solveMem(prices, n, idx + 1, 1, dp);
        int skip = solveMem(prices, n, idx + 1, 0, dp);
        profit = max(sell, skip);
    }

    dp[idx][buy] = profit;
    return dp[idx][buy];
}

int maxProfit2(vector<int> prices, int n)
{
    int idx = 0;
    int buy = 1;
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return solveMem(prices, n, idx, buy, dp);
}

int solveTab(vector<int> prices, int n)
{
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][1] = -prices[0];
    dp[0][0] = 0;
    for (int idx = 1; idx < n; idx++)
    {
        for (int buy = 0; buy < 2; buy++)
        {

            if (buy)
            {
                int buyK = -prices[idx] + dp[idx - 1][0];
                int skip = dp[idx - 1][1];
                dp[idx][buy] = max(buyK, skip);
            }

            else
            {
                int sell = prices[idx] + dp[idx - 1][1];
                int skip = dp[idx - 1][0];
                dp[idx][buy] = max(sell, skip);
            }
        }
    }

    return dp[n - 1][0];
}

int maxProfit3(vector<int> prices, int n)
{
    return solveTab(prices, n);
}

int main()
{

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int n = prices.size();
    int ans = maxProfit3(prices, n);
    cout << ans << endl;
    return 0;
}