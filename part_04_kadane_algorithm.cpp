#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumArray(vector<int> arr)
{
    int maxSum = INT_MIN;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

int maxSumArrayBetter(vector<int> arr)
{

    int maxSum = INT_MIN;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

int maxSumArrayBest(vector<int> arr)
{

    int maxSum = INT_MIN;

    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {

        sum += arr[i];
        maxSum = max(maxSum, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxSum;
}

int main()
{

    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = maxSumArrayBest(arr);
    cout << ans << endl;
    return 0;
}