#include <bits/stdc++.h>
using namespace std;

int main()
{

    string n = '00000010100101000001111010011100';
    int ans = 0;
    for (int i = 0; i < n.size(); i++)
    {
        ans = ans * 10 + (n[i] - '0');
    }

    cout<< ans;

    return 0;
}

/*
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       string temp = to_string(n);
    //    reverse(temp.begin(),temp.end());
       uint32_t ans = 0;
       for(int i=0; i<temp.begin(); i++){
          ans = ans * 10 + (temp[i] - '0'); 
       }

       return ans;
    }
};
*/