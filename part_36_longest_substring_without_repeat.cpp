#include <bits/stdc++.h>
using namespace std;

int longestNonRepeatSubstr(string s)
{

    int maxLen = INT_MIN;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        unordered_set<char> st;
        for (int j = i; j < n; j++)
        {
            string substr = s.substr(i, j);
            int count = 0;
            for (int k = 0; k < substr.size(); k++)
            {
                if (st.find(substr[k]) != st.end())
                {
                    break;
                }

                else
                {
                    st.insert(substr[k]);
                    count++;
                }
            }

            maxLen = max(maxLen, count);
        }
    }

    return maxLen;
}
int longestNonRepeatSubstrBetter(string s)
{

    int maxLen = INT_MIN;
    int n = s.length();

    unordered_set<char> st;
    int start = 0;
    for (int end = 0; end < n; end++)
    {
        string str = s.substr(start, end);
        if (st.find(str[end]) != st.end())
        {
            while (start < end && st.find(str[end]) != st.end())
            {

                st.erase(str[start]);
                start++;
            }
        }
        st.insert(str[end]);
        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
}

int main()
{
    string s = "pwwkew";
    int len = longestNonRepeatSubstrBetter(s);
    cout << "Length of the longest non-repeating substring is " << len << endl;

    return 0;
}