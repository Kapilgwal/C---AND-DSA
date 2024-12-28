#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxprodArray(vector<int> arr)
{
    int maxprod = INT_MIN;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int prod = 1;
            for (int k = i; k <= j; k++)
            {
                prod *= arr[k];
            }

            maxprod = max(maxprod, prod);
        }
    }

    return maxprod;
}

int maxprodArrayBetter(vector<int> arr)
{

    int maxprod = INT_MIN;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int prod = 1;
        for (int j = i; j < n; j++)
        {
            prod *= arr[j];
            maxprod = max(maxprod, prod);
        }
    }

    return maxprod;
}

int maxprodArrayBest(vector<int> arr)
{

    int maxprod = INT_MIN;

    int n = arr.size();
    int prod = 1;
    for (int i = 0; i < n; i++)
    {

        prod *= arr[i];
        maxprod = max(maxprod, prod);

        if (prod == 0)
        {
            prod = 1;
        }
    }

    return maxprod;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 0};
    int ans = maxprodArrayBest(arr);
    cout << ans << endl;
    return 0;
}