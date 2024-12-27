#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isDuplicate(vector<int> &nums)
{

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }

    return false;
}

bool isDuplicateBetter(vector<int> &nums){
    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size()-1; i++){
        if(nums[i] == nums[i+1]){
            return true;
        }
    }

    return false;
}

bool isDuplicateBetter2(vector<int> &nums){
    unordered_map<int,int> mp;

    for(auto it : nums){
        mp[it]++;
    }

    for(auto it : mp){
        if(it.second > 1){
            return true;
        }
    }

    return false;
}


int main()
{

    vector<int> nums = {1, 2, 3, 1};

    bool ans1 = isDuplicate(nums);
    bool ans2 = isDuplicateBetter(nums);
    bool ans3 = isDuplicateBetter2(nums);
    cout << ans3 << endl;

    return 0;
}