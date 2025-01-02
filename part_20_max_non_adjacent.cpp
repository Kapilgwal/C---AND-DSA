#include<bits/stdc++.h>
using namespace std;

int solveRec(vector<int> arr,int idx,int n){
    if(idx >= n){
        return 0;
    }

    int take = arr[idx] + solveRec(arr,idx+2,n);
    int notTake = solveRec(arr,idx+1,n);

    return max(notTake,take);
}

int maxNonAdjacent(vector<int> arr){
    int idx = 0;
    return solveRec(arr,idx,arr.size());
}

int solveMemo(vector<int> arr,int idx,int n,vector<int> &dp){
    if(idx >= n){
        return 0;
    }

    if(dp[idx] != -1){
        return dp[idx];
    }

    int take = arr[idx] + solveMemo(arr,idx+2,n,dp);
    int notTake = solveMemo(arr,idx+1,n,dp);

    dp[idx] = max(notTake,take);
    return dp[idx];
}

int maxNonAdjacentMemo(vector<int> arr){
    int idx = 0;
    int n = arr.size();
    vector<int> dp(n+1,-1);
    return solveMemo(arr,idx,arr.size(),dp);
}

int maxNonAdjacentTab(vector<int> arr){
    int n = arr.size();
    vector<int> dp(n+1,0);
    dp[0] = arr[0];
    dp[1] = arr[1];

    for(int i=2; i<n; i++){
        int take = arr[i] + dp[i-2];
        int notTake = dp[i-1];

        dp[i] = max(take,notTake);
    }

    return dp[n-1];
}

int maxNonAdjacentSpcOpm(vector<int> arr){
    int n = arr.size();
    int prev2 = arr[0];
    int prev1 = max(arr[1],arr[0]);

    for(int i=2; i<n; i++){
        int take = arr[i] + prev2;
        int notTake = prev1;

        int curr = max(take,notTake);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {

vector<int> arr = {1,2,3,1,3,5,8,1,9};
cout<<maxNonAdjacent(arr)<<endl;
cout<<maxNonAdjacentMemo(arr)<<endl;
cout<<maxNonAdjacentTab(arr)<<endl;
cout<<maxNonAdjacentSpcOpm(arr)<<endl;

return 0;
}