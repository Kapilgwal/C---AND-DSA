#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> arr, int idx, int n)
{
    if (idx >= n)
    {
        return 0;
    }

    int take = arr[idx] + solveRec(arr, idx + 2, n);
    int notTake = solveRec(arr, idx + 1, n);

    return max(notTake, take);
}

int maxNonAdjacent(vector<int> arr)
{
    int idx = 0;
    return solveRec(arr, idx, arr.size());
}

int solveMemo(vector<int> arr, int idx, int n, vector<int> &dp)
{
    if (idx >= n)
    {
        return 0;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int take = arr[idx] + solveMemo(arr, idx + 2, n, dp);
    int notTake = solveMemo(arr, idx + 1, n, dp);

    dp[idx] = max(notTake, take);
    return dp[idx];
}

int maxNonAdjacentMemo(vector<int> arr)
{
    int idx = 0;
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    return solveMemo(arr, idx, arr.size(), dp);
}

int maxNonAdjacentTab(vector<int> arr)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    dp[0] = arr[0];
    dp[1] = arr[1];

    for (int i = 2; i < n; i++)
    {
        int take = arr[i] + dp[i - 2];
        int notTake = dp[i - 1];

        dp[i] = max(take, notTake);
    }

    return dp[n - 1];
}

int maxNonAdjacentSpcOpm(vector<int> arr)
{
    int n = arr.size();
    int prev = arr[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick += prev2;
        int nonPick = 0 + prev;

        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}

int HouseRobbery(vector<int> arr)
{
    vector<int> arr1, arr2;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i != 0)
        {
            arr1.push_back(arr[i]);
        }

        if (i != 0)
        {
            arr2.push_back(arr[i]);
        }
    }

    int ans1 = maxNonAdjacentSpcOpm(arr1);
    int ans2 = maxNonAdjacentSpcOpm(arr2);

    return max(ans1, ans2);
}

int main()
{

    vector<int> arr = {1, 5, 1, 2, 6};
    int ans = HouseRobbery(arr);
    cout << ans << endl;

    return 0;
}