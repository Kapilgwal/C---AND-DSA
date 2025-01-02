#include <bits/stdc++.h>
using namespace std;

int solveRec(string s1,string s2,int i,int j,int n,int m){
    if(i >=n or j>=m){
        return 0;
    }

    if(s1[i]==s2[j]){
        return 1+solveRec(s1,s2,i+1,j+1,n,m);
    }

    else{
        return max(solveRec(s1,s2,i+1,j,n,m),solveRec(s1,s2,i,j+1,n,m));
    }
}

int longestSubsequence(string s1,string s2){
    int i = 0;
    int j = 0;
    int m = s1.length();
    int n = s2.length();

    return solveRec(s1,s2,i,j,n,m);

}

int solveMemo(string s1,string s2,int i,int j,int n,int m,vector<vector<int>> &dp){
    if(i >=n or j>=m){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s1[i]==s2[j]){
        dp[i][j] = 1+solveMemo(s1,s2,i+1,j+1,n,m,dp);
    }

    else{
        dp[i][j] = max(solveMemo(s1,s2,i+1,j,n,m,dp),solveMemo(s1,s2,i,j+1,n,m,dp));
    }

    return dp[i][j];
}

int longestSubsequenceMemo(string s1,string s2){
    int i = 0;
    int j = 0;
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1,-1));

    return solveMemo(s1,s2,i,j,n,m,dp);

}

int longestSubsequenceTab(string s1,string s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));


    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i]==s2[j]){
                dp[i][j] = 1+dp[i-1][j-1];
            }

            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int longestSubsequenceSpcOpm(string s1,string s2){
    int n = s1.length();
    int m = s2.length();
    // vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    vector<int> prev(n+1,0);
    vector<int> curr(n+1,0);



    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i]==s2[j]){
                curr[j] = 1+prev[j-1];
            }

            else{
                curr[j] = max(prev[j],prev[j-1]);
            }
        }

        prev = curr;
    }

    return prev[m];
}


int main()
{
    string s1 = "adebc";
    string s2 = "dcadb";

    cout << longestSubsequence(s1, s2) << endl;
    cout << longestSubsequenceMemo(s1, s2) << endl;
    cout << longestSubsequenceTab(s1, s2) << endl;
    cout << longestSubsequenceSpcOpm(s1, s2) << endl;

    return 0;
}