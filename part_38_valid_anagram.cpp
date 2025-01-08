#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s = "rat";
    string t = "car";

    unordered_map<char, int> mp1, mp2;

    for (int i = 0; i < s.length(); i++)
    {
        mp1[s[i]]++;
        mp2[t[i]]++;
    }

    if (mp1 == mp2)
    {
        cout << "Valid Anagram\n";
    }
    else
    {
        cout << "Invalid Anagram\n";
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s == t)
    {
        cout << "Valid Anagram\n";
    }
    else
    {
        cout << "Invalid Anagram\n";
    }

    return 0;
}