#include <bits/stdc++.h>
using namespace std;

int longestRepeatingCharReplacement(string s, int k)
{
    int maxLen = INT_MIN;

    for (int i = 0; i < s.length(); i++)
    {
        string str = "";
        for (int j = i; j < s.length(); j++)
        {
            str += s[j];
            unordered_map<int, int> freq;
            int maxFreq = 0;

            for (auto it : str)
            {
                freq[it]++;
                maxFreq = max(maxFreq, freq[it]);
            }

            int replacement = str.size() - maxFreq;
            if (replacement <= k)
            {
                maxLen = max(maxLen, (int)str.size());
            }
        }
    }

    return maxLen;
}

int longestRepeatingCharReplacementBetter(string s, int k)
{
    int maxLen = INT_MIN;
    int maxCount = INT_MIN;
    string str = "";
    int l = 0;
    unordered_map<int, int> freq;
    for (int r = 0; r < s.length(); r++)
    {
        freq[s[r]]++;
        maxCount = max(maxCount,freq[s[r]]);

        if((r - l + 1) - maxLen > k){
            freq[s[l]]--;
            l++;
        }

        maxLen = max(maxLen,r - l + 1);
    }

    return maxLen;
}

int main()
{

    string s = "ABAB";
    int k = 2;
    int len = longestRepeatingCharReplacement(s, k);
    cout << len << endl;

    return 0;
}