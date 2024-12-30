#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> arr = {0, 1, 2};
    int n = arr.size();
    int sum1 = 0;
    int sum2 = ((n)*(n+1))/2;

    for(int i=0; i<n; i++){
        sum1 += arr[i];
    }

    cout<<sum2 - sum1<<endl;

    return 0;
}