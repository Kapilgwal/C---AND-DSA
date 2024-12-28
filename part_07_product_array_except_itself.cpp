#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptItself(vector<int> nums)
{
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {

        int prod = 1;

        for (int j = 0; j < n; j++)
        {

            if (i == j)
            {
                continue;
            }

            else
            {
                prod = prod * nums[j];
            }
        }

        ans.push_back(prod);
    }

    return ans;
}

vector<int> productExceptItselfBetter(vector<int> nums)
{
    int n = nums.size();
    vector<int> left(n);
    vector<int> right(n);

    left[0] = 1;
    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }

    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int prod = left[i] * right[i];
        ans.push_back(prod);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = productExceptItselfBetter(nums);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}