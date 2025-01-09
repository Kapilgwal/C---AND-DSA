#include<bits/stdc++.h>
using namespace std;

int main() {

string s = "abba";
string ans = "";
int len = 0;
int maxLen = 0;

for(int i=0; i<s.length(); i++){
    string temp = "";
    for(int j=i; j<s.length(); j++){
        temp += s[j];

        string temp2 = temp;
        reverse(temp2.begin(),temp2.end());

        if(temp == temp2){
            if(temp.length() > maxLen){
                ans = temp;
                maxLen = temp.length();
            }
        }
    }
}

cout<<ans;

return 0;
}