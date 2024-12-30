#include <iostream>
#include <vector>
using namespace std;

bool isPresent(vector<int> arr, int tar)
{

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == tar)
        {
            return true;
        }
    }

    return false;
}

bool isPresentBetter(vector<int> arr, int tar)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == tar)
        {
            return true;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= tar && tar <= arr[mid])
            {
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }

        else
        {
            if (arr[low] <= tar && tar <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return false;
}

int main()
{

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 3;

    cout << isPresentBetter(arr, target) << endl;

    return 0;
}