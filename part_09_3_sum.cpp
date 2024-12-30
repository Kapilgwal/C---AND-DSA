#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> arr)
{
    set<vector<int>> st;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);

                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSumBetter(vector<int> arr)
{
    set<vector<int>> stt;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        set<int> st;
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];

            if (st.find(sum) != st.end())
            {
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(-sum);

                sort(temp.begin(), temp.end());
                stt.insert(temp);
            }

            st.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(stt.begin(), stt.end());
    return ans;
}
vector<vector<int>> threeSumBest(vector<int> arr)
{
    set<vector<int>> stt;
    sort(arr.begin(), arr.end());
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int low = i + 1;
        int high = n - 1;

        while (low < high)
        {
            int sum = arr[i] + arr[low] + arr[high];

            if (sum == 0)
            {
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[low]);
                temp.push_back(arr[high]);
                sort(temp.begin(), temp.end());

                stt.insert(temp);
                low++;
                high--;
            }

            else if (sum > 0)
            {
                high--;
            }

            else
            {
                low++;
            }
        }
    }

    vector<vector<int>> ans(stt.begin(), stt.end());
    return ans;
}

int main()
{

    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSumBest(arr);

    for (auto it : ans)
    {
        for (auto j : it)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}