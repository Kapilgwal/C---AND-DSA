#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMin(vector<int> arr)
{
    int mini = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        mini = min(arr[i], mini);
    }

    return mini;
}

int findMinBetter(vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;
    while (low < high)
    {
        int mid = (low + high) / 2;
        int ele = arr[mid];

        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }

        else
        {
            ans = min(ans, arr[high]);
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int ans = findMinBetter(arr);
    cout << ans << endl;

    return 0;
}