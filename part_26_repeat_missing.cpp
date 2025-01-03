#include <bits/stdc++.h>
using namespace std;

pair<int, int> repeat_missing(vector<int> arr)
{
    int n = arr.size();

    int repeat = -1;
    int missing = -1;

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;

        for (auto it : arr)
        {
            if (it == i)
            {
                cnt++;
            }
        }

        if (cnt == 2)
        {
            repeat = i;
        }

        if (cnt == 0)
        {
            missing = i;
        }
    }

    return {repeat, missing};
}

pair<int, int> repeat_missing_better(vector<int> arr)
{
    int n = arr.size();

    unordered_map<int, int> mp;

    for (auto it : arr)
    {
        mp[it]++;
    }

    for (int i = 1; i <= n; i++)
    {
        mp[i]++;
    }

    int repeat = -1;
    int missing = -1;

    for (auto it : mp)
    {
        if (it.second == 1)
        {
            missing = it.first;
        }

        if (it.second == 3)
        {
            repeat = it.first;
        }
    }

    return {repeat, missing};
}

pair<int, int> repeat_missing_optimal(vector<int> arr)
{
    int n = arr.size();
    int sum1 = 0;
    int sum2 = 0;

    int sum11 = ((n) * (n + 1)) / 2;
    int sum22 = ((n) * (n + 1) * (2 * n + 1)) / 6;

    for (auto it : arr)
    {
        sum1 += it;
        sum2 += (it * it);
    }

    int val2 = sum22 - sum2;
    int val1 = sum11 - sum1;

    val2 = val2 / val1;

    int x = (val1 + val2) / 2;
    int y = x - val1;

    return {x, y};
}

int main()
{

    vector<int> arr = {3, 1, 2, 5, 4, 6, 7, 5};
    // pair<int, int> p1 = repeat_missing(arr);
    // pair<int, int> p1 = repeat_missing_better(arr);
    pair<int, int> p1 = repeat_missing_optimal(arr);
    cout << p1.first << " " << p1.second << endl;

    return 0;
}