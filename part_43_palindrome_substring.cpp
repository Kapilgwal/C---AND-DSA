#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s = "aaa";
    int ans = 0;

    for (int i = 0; i < s.length(); i++)
    {
        string temp = "";
        for (int j = i; j < s.length(); j++)
        {
            temp += s[j];

            string temp2 = temp;
            reverse(temp2.begin(), temp2.end());

            if (temp == temp2)
            {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}