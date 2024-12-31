#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> coins, int tar, int idx, int n)
{
    if (idx == 0)
    {
        return (tar % coins[0] == 0);
    }

    int notTake = solveRec(coins, tar, idx - 1, n);

    int take = 0;
    if (tar >= coins[idx])
    {
        take = solveRec(coins, tar - coins[idx], idx, n);
    }

    int ans = take + notTake;
    return ans;
}

int recurrsion(vector<int> coins, int tar)
{
    int n = coins.size();
    int index = n - 1;
    return solveRec(coins, tar, index, n);
}

int solveMem(vector<int> coins, int tar, int idx, int n, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        return (tar % coins[0] == 0);
    }

    if (dp[idx][tar] != -1)
    {
        return dp[idx][tar];
    }

    int notTake = solveMem(coins, tar, idx - 1, n, dp);

    int take = 0;
    if (tar >= coins[idx])
    {
        take = solveMem(coins, tar - coins[idx], idx, n, dp);
    }

    int ans = take + notTake;
    dp[idx][tar] = ans;
    return dp[idx][tar];
}

int memorisation(vector<int> coins, int tar)
{
    int n = coins.size();
    int index = n - 1;
    vector<vector<int>> dp(n + 1, vector<int>(tar + 1, -1));
    return solveMem(coins, tar, index, n, dp);
}

int solveTab(vector<int> coins, int tar, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(tar + 1, 0));
    
    for(int i=0; i<=tar; i++){
        if(i%coins[0] == 0){
            dp[0][i] = 1;
        }
    }

    for(int i=1; i<n; i++){
        for(int target = 0; target <= tar; target++){
            int notTake = dp[i-1][target];

            int take = 0;
            if(coins[i] <= target){
                take = dp[i][target-coins[i]];

            }

            dp[i][target] = notTake + take;
        }
    }

    return dp[n-1][tar];
    
}

int tabulation(vector<int> coins, int tar)
{
    int n = coins.size();
    int index = n - 1;
    return solveTab(coins, tar, n);
}

int main()
{

    vector<int> coins = {1, 2, 3};
    int target = 4;
    int ans1 = recurrsion(coins, target);
    int ans2 = memorisation(coins, target);
    int ans3 = tabulation(coins, target);
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
    /*
    1 1 1 1
    1 3
    2 2
    1 1 2
    */
    return 0;
}