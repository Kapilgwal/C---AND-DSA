#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool bruteForce(vector<int> &arr, int target)
{

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return true;
            }
        }
    }

    return false;
}

bool better(vector<int> arr, int target)
{
    unordered_map<int, int> mp;

    for (auto it : arr)
    {
        mp[it]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        int temp = target - arr[i];

        if (mp.find(temp) != mp.end())
        {
            return true;
        }
    }

    return false;
}

bool best(vector<int> arr, int target)
{
    int i = 0;
    int j = arr.size() - 1;

    while (i < j)
    {
        int sum = arr[i] + arr[j];

        if (sum == target)
        {
            return true;
        }

        else if (sum > target)
        {
            j--;
        }

        else
        {
            i++;
        }
    }

    return false;
}

int main()
{

    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    bool ans1 = bruteForce(arr, target);
    bool ans2 = better(arr, target);
    bool ans3 = best(arr, target);

    if (ans2)
    {
        cout << "Target found" << endl;
    }

    else
    {
        cout << "Target not found" << endl;
    }

    return 0;
}