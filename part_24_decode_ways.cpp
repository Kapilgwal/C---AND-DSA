#include <bits/stdc++.h>
using namespace std;

bool isValid(int num)
{
    return num >= 1 && num <= 26;
}

int solveRec(string s, int idx, int n)
{
    if (idx >= n)
    {
        return 1;
    }

    if (s[idx] == '0')
    {
        return 0;
    }

    int ways = solveRec(s, idx + 1, n);

    if (idx + 1 < s.length() && stoi(s.substr(idx, idx + 1)) <= 26)
    {
        ways += solveRec(s, idx + 2, n);
    }

    return ways;
}

int decodeWays(string s)
{
    int idx = 0;
    int n = s.length();
    return solveRec(s, idx, n);
}

int main()
{
    string s = "12";
    int ans = decodeWays(s);
    cout << ans << endl;

    return 0;
}