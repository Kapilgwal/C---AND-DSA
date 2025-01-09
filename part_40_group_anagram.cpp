#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> makeGroupAnagram(vector<string> anagram)
{
    map<string, vector<string>> anagrams;
    for (string word : anagram)
    {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        anagrams[sortedWord].push_back(word);
    }

    vector<vector<string>> ans;
    for (auto it : anagrams)
    {

        vector<string> temp;
        for (auto j : it.second)
        {
            temp.push_back(j);
        }

        ans.push_back(temp);
    }

    return ans;
}

int main()
{

    vector<string> anagram = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupAnagram = makeGroupAnagram(anagram);

    for (auto it : groupAnagram)
    {
        for (auto j : it)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}